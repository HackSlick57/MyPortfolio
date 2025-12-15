#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string getChoiceName(int choice) {
    if (choice == 0) return "Rock";
    if (choice == 1) return "Paper";
    return "Scissors";
}

int determineWinner(int player, int computer) {
    if (player == computer)
        return 0;

    if ((player == 0 && computer == 2) ||
        (player == 1 && computer == 0) ||
        (player == 2 && computer == 1))
        return 1;

    return -1;
}

int main() {
    srand(time(0));

    int playerChoice;
    int computerChoice;
    int wins = 0, losses = 0, draws = 0;
    int compRock = 0, compPaper = 0, compScissors = 0;
    int rounds = 0;
    char playAgain = 'y';

    cout << "=== Rock Paper Scissors Simulator (Stats Mode) ===\n";

    while (playAgain == 'y' || playAgain == 'Y') {
        cout << "\n0 - Rock\n1 - Paper\n2 - Scissors\n";
        cout << "Enter your choice: ";
        cin >> playerChoice;

        if (playerChoice < 0 || playerChoice > 2) {
            cout << "Invalid choice.\n";
            continue;
        }

        computerChoice = rand() % 3;
        rounds++;

        if (computerChoice == 0) compRock++;
        else if (computerChoice == 1) compPaper++;
        else compScissors++;

        cout << "You: " << getChoiceName(playerChoice) << endl;
        cout << "Computer: " << getChoiceName(computerChoice) << endl;

        int result = determineWinner(playerChoice, computerChoice);

        if (result == 1) {
            cout << "You win!\n";
            wins++;
        } else if (result == -1) {
            cout << "You lose!\n";
            losses++;
        } else {
            cout << "Draw!\n";
            draws++;
        }

        cout << "\nCurrent Stats:\n";
        cout << "Rounds: " << rounds << endl;
        cout << "Wins: " << wins << " Losses: " << losses << " Draws: " << draws << endl;

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\n---Final Statistics---\n";
    cout << "Total Rounds: " << rounds << endl;

    if (rounds > 0) {
        cout << "Win %: " << (wins * 100.0 / rounds) << endl;
        cout << "Loss %: " << (losses * 100.0 / rounds) << endl;
        cout << "Draw %: " << (draws * 100.0 / rounds) << endl;
    }

    cout << "\nComputer Choice Distribution:\n";
    cout << "Rock: " << compRock << endl;
    cout << "Paper: " << compPaper << endl;
    cout << "Scissors: " << compScissors << endl;

    return 0;
}
