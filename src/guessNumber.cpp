#include<iostream>
using namespace std;
void guessNumber();
int generateLength(int difficulty);
int main() {
    guessNumber();
    return 0;
}
void guessNumber() {
    srand(time(0));     // This line makes rand() generate random numbers each execution
    cout << "#######################################################" << endl;
    cout << "                     GUESS THE NUMBER                  " << endl;
    cout << "#######################################################" << endl << endl;
    int play = 1;
    while(play != 0) {
        int *difficulty = new int(0);
        cout << "Please enter the difficulty of the game (1 - 5):    ";
        cin >> *difficulty;
        cout << "#######################################################" << endl;
        int attempts = 10;
        int *number = new int(rand() % generateLength(*difficulty));
        if((number == 0)) {
            number++;
        }
        bool *guessed = new bool(false);
        int *userChoice = new int(0);
        cout << "Please Guess a number between 1 and " << generateLength(*difficulty) - 1 << ":    ";
        cin >> *userChoice;
        cout << "#######################################################" << endl;
        while(attempts--) {
            if(*userChoice == *number) {
                cout << "#######################################################" << endl;
                cout << "                YOU GUESSED THE NUMBER!! ;)              " << endl;
                cout << "#######################################################" << endl << endl;
                *guessed = true;
                break;
            }
            else if(abs(*userChoice - *number) > 10) {
                cout << "#######################################################" << endl;
                cout << "YOUR GUESS IS TOO FAR. Attempts left: " << attempts << ". GUESS AGAIN         " << endl;
                cout << "#######################################################" << endl << endl;
                cout << "Please Guess a number between 1 and 20:    ";
                cin >> *userChoice;
            }
            else if(abs(*userChoice - *number) < 10) {
                cout << "#######################################################" << endl;
                cout << "YOUR GUESS IS NEAR. Attempts left: " << attempts << ". GUESS AGAIN          " << endl;
                cout << "#######################################################" << endl << endl;
                cout << "Please Guess a number between 1 and 20:    ";
                cin >> *userChoice;
            }
        }
        if(attempts == 0 && !guessed) {
            cout << "#######################################################" << endl;
            cout << "                YOU COULDN'T GUESS THE NUMBER :(               " << endl;
            cout << "#######################################################" << endl << endl;
        }
        delete guessed;
        delete number;
        delete userChoice;
        delete difficulty;
        cout << "If you want to exit, press 0. Otherwise press any other digit:    ";
        cin >> play;
        cout << endl << endl;
    }
    return;
}
int generateLength(int difficulty) {
    switch(difficulty) {
        case 1:
            return 21;
        case 2:
            return 41;
        case 3:
            return 61;
        case 4:
            return 81;
        default:
            return 101;
    }
    return -1;
}