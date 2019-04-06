#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

// simulates rolling a die by giving a random number between 1 and 6
int rollDie(){
    return rand()%6+1;
}


// returns true if the game is over due to a balance of 0
bool gameOver(int balance){
    if (balance ==0){
        return true;
    }
    return false;
}
//prints out the win percentage of the game
void winPercent(int win, int lose){
    if ((win + lose) == 0){
        cout << "You didn't play at all, you have no winning percentage." << endl;
    }else{
        cout << "You won " << win << " time out of " << win+lose<< " for a winning percentage of " << (win * 100)/(win + lose) << "%" << endl;
    }
}
// checks if the wager entered is valid
bool checkValidBet(int bet, int balance){
    if (bet < 0 || bet > balance || bet > 100){
        return false;
    }
    return true;
}
//checks if the point entered is valid
bool checkValidPoint(int point){
    if (point > 6 || point < 1){
        return false;
    }
    return true;
}
//plays 1 game with 3 dice rolls and returns true if the user wins
bool playOneGame(){
    int point;
    int roll;
    cout << "Enter your point value (1 - 6): ";
    cin >> point;
    while (!(checkValidPoint(point))){
        cout << "Error: Enter your point value, must be between 1 and 6: ";
        cin >> point;
        cout << endl;
    }
    for(int i = 0; i < 3; i++){
        roll = rollDie();
        cout << "Roll #" << i << " is " << roll << endl;
        if (roll == point){
            cout << " ** You win! **" << endl;
            return true;
            break;
        }
    }
    cout << " ** You Lose **" << endl;
    return false;


}
int main()
{
    srand(time(NULL));
    int balance = 100;
    int win = 0;
    int lose = 0;
    int wager;
    while(true){
        cout << "Account balance $" << balance << endl;
        cout << "Enter wager (0 to exit): " << endl;
        cin >> wager;
        cout << endl;
        if (wager == 0){
            break;
        }
        while (!(checkValidBet(wager,balance))){
            cout << "Error: You must wager between $1 and $100 (type 0 to exit): ";
            cin >> wager;
            if (wager == 0){
                break;
            }
            cout << endl;
        }
        if (playOneGame()){
            win++;
            balance = balance+ wager;
        }else {
            lose++;
            balance = balance - wager;
        }
        if (balance == 0){
            cout << "Game over, you are out of money!" << endl;
        }
    }
    cout << "Your final account balance is $" << balance << endl;
    winPercent(win,lose);
    return 0;
}
