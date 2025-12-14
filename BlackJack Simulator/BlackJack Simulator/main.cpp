#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class Card{
public:
    int value;
    Card(){
        value = rand() % 13 + 1;
    }

    int getValue() {
        if (value >= 2 && value <= 10) return value;
        if (value > 10) return 10;
        return 11;
    }

    string toString() {
        if (value == 1) return "A";
        if (value == 11) return "J";
        if (value == 12) return "Q";
        if (value == 13) return "K";
        return to_string(value);
    }
};

class Hand {
public:
    vector<Card> cards;
    void addCard(Card c) {
        cards.push_back(c);
    }
    int getTotal() {
        int total = 0;
        int aces = 0;
        for (Card c : cards) {
            total += c.getValue();
            if (c.value == 1) aces++;
        }

        while (total > 21 && aces > 0) {
            total -= 10;
            aces--;
        }
        return total;
    }

    void printHand(bool hideFirst=false) {
        for (size_t i = 0; i < cards.size(); i++) {
            if (i == 0 && hideFirst) cout << "[Hidden] ";
            else cout << cards[i].toString() << " ";
        }
        cout << endl;
    }
};

int main() {
    srand(time(0));
    int balance = 100;
    int wins = 0;
    int losses = 0;
    char playAgain = 'y';
    
    cout << "---Blackjack Simulator---"<<endl;
    cout << "Starting Balance: " << balance << endl;
    
    while (playAgain == 'y' && balance > 0) {
        Hand player;
        Hand dealer;
        
        int bet;
        cout << "\nEnter your bet (Current Balance: " << balance << "): ";
        cin >> bet;
        
        if (bet > balance || bet <= 0) {
            cout << "Invalid bet amount. Try again.\n";
            continue;
        }
        
        player.addCard(Card());
        player.addCard(Card());
        dealer.addCard(Card());
        dealer.addCard(Card());
        
        cout << "Dealer's Hand: ";
        dealer.printHand(true);
        cout << "Your Hand: ";
        player.printHand();
        cout << "Total: " << player.getTotal() << endl;
        
        char choice;
        while (true) {
            if (player.getTotal() > 21) {
                cout << "Bust! You exceeded 21."<<endl;
                break;
            }
            cout << "\nDo you want to Hit(h) or Stand(s)? ";
            cin >> choice;
            if (choice == 'h') {
                Card newCard;
                player.addCard(newCard);
                cout << "\nYou drew: " << newCard.toString() << endl;
                cout << "Your Hand: ";
                player.printHand();
                cout << "Total: " << player.getTotal() << endl;
            } else if (choice == 's') {
                break;
            } else {
                cout << "Invalid input, choose 'h' or 's'."<<endl;
            }
        }
        
        if (player.getTotal() <= 21) {
            cout << "\nDealer's Turn:"<<endl;
            dealer.printHand();
            while (dealer.getTotal() < 17) {
                Card newCard;
                dealer.addCard(newCard);
                cout << "Dealer draws: " << newCard.toString() << endl;
                cout << "Dealer's Hand: ";
                dealer.printHand();
            }
            cout << "Dealer Total: " << dealer.getTotal() << endl;
        }
        
        int playerTotal = player.getTotal();
        int dealerTotal = dealer.getTotal();
        
        cout << "\n---Round Result---\n";
                if (playerTotal > 21) {
                    cout << "You busted. Dealer wins.\n";
                    balance -= bet;
                    losses++;
                } else if (dealerTotal > 21) {
                    cout << "Dealer busted. You win!\n";
                    balance += bet;
                    wins++;
                } else if (playerTotal > dealerTotal) {
                    cout << "You win!\n";
                    balance += bet;
                    wins++;
                } else if (dealerTotal > playerTotal) {
                    cout << "Dealer wins.\n";
                    balance -= bet;
                    losses++;
                } else {
                    cout << "It's a tie!\n";
                }

                cout << "Current Balance: " << balance << endl;
                cout << "Wins: " << wins << " | Losses: " << losses << endl;

                if (balance <= 0) {
                    cout << "You are out of money. Game over.\n";
                    break;
                }

                cout << "\nDo you want to play another round? (y/n): ";
                cin >> playAgain;
            }

            cout << "\n---Final Stats---\n";
            cout << "Final Balance: " << balance << endl;
            cout << "Total Wins: " << wins << " | Total Losses: " << losses << endl;
            cout << "Thank you for playing!\n";
        return 0;
    }
