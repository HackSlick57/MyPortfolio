#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    
    int dice;
    int rolls;
    
    cout<<"---Dice Probability Simulator---"<<endl;
    cout<<"Enter number of dice (Between 1 or 2): ";
    cin>>dice;
    
    cout<<"Enter number of rolls: ";
    cin>>rolls;
    
    if((dice != 1 && dice != 2)||rolls <= 0){
          cout << "Invalid input. Program exiting."<<endl;
          return 0;
      }
    else{
            int count[13] = {0};

            for (int i = 0; i < rolls; i++) {
                int die1 = rand() % 6 + 1;
                int die2 = rand() % 6 + 1;
                int sum = die1 + die2;
                count[sum]++;
            }

            cout << "\nResults for 2 Dice: "<<endl;
            cout << "Sum\tCount\tProbability(%)"<<endl;

            for (int i = 2; i <= 12; i++) {
                double probability = (count[i] * 100.0) / rolls;
                cout << i << "\t"
                     << count[i] << "\t"
                     << probability << "%\n";
            }
        }

        return 0;
}
