/* 
   CH-230-A 
   a9_p5.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    
    // get user input
    cout << "What's your name?" << endl;
    string name;
    getline(cin, name);

    // generate random number between 1 and 100
    srand(static_cast<unsigned int>(time(0)));
    int random_num = (rand() % 100) + 1;

    // game loop
    int tries = 0;
    int guess = 0;

    while (guess != random_num) {
        // get guess and evaluate it
        cout << "Enter guess (integer): ";
        cin >> guess;
        tries++;

        if (guess > random_num) {
            cout << "Wrong! 😞 Guess is too high!" << endl;
        } else if (guess < random_num) {
            cout << "Wrong! 😡 Guess is too low!" << endl;
        } else {
            cout << "You finally got it! 🥳 It took you " << tries 
                << " tries! Good job, " << name << "!" << endl;
        }
    }

    return 0;
}
