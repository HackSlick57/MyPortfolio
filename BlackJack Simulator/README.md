# Blackjack Simulator with Betting

## Description
This project simulates a console-based Blackjack game between a player and a dealer, including betting and balance tracking.  
It demonstrates object-oriented programming (OOP), loops, conditionals, and state management in C++.

## Features
- Play multiple rounds of Blackjack  
- Player vs dealer gameplay with standard rules  
- Hit or Stand options  
- Ace value adjustment (11 → 1 if total exceeds 21)  
- Player balance and betting system  
- Track total wins and losses  
- Console-based input/output  

## Skills Demonstrated
- Object-Oriented Programming (classes: `Card`, `Hand`)  
- Loops and conditional statements  
- Vectors for dynamic data handling  
- Random number generation for card draws  
- Input validation  
- State management (balance, bets, wins/losses)  

## How to Run
1. Open the project in a C++ IDE (Code::Blocks, Visual Studio, or similar).  
2. Compile the program.  
3. Run the program and follow the console instructions:
   - Enter your bet before each round.  
   - Decide whether to Hit (`h`) or Stand (`s`) on your turn.  
   - Observe dealer actions and round results.  
   - Continue playing rounds until you quit or run out of balance.

## Example Gameplay
Starting Balance: 100
Enter your bet: 20

Dealer’s Hand: [Hidden] 9
Your Hand: 10 7
Total: 17
Do you want to Hit (h) or Stand (s)? s

Dealer’s Turn:
Dealer’s Hand: 9 6
Dealer draws: 7
Dealer’s Hand: 9 6 7
Dealer Total: 22

---Round Result---
Dealer busted. You win!
Current Balance: 120
Wins: 1 | Losses: 0
Play another round? (y/n)
