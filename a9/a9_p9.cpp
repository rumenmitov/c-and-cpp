/* 
   CH-230-A 
   a9_p9.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

string encrypt(string str);

int main(void) {

    // available words
    const string str_arr[17] = {
        "computer",
        "television",
        "keyboard",
        "laptop",
        "mouse",
        "bait",
        "away",
        "long",
        "when",
        "may",
        "leave",
        "paradise",
        "boat",
        "coat",
        "moat",
        "moot",
        "boot"
    };

    // random number
    srand(static_cast<unsigned int>(time(0)));

    // game loop
    bool isQuit = false;
    while (!isQuit) {

        // get random word and encrypt it
        int rand_index = rand() % 17;
        string word = str_arr[rand_index];
        string enc_word = encrypt(word);

        string guess;
        int tries = 0;

        // get user guess and print result
        while (guess != word) {
            cout << "Word is: " << enc_word << endl;
            cout << "Your guess: ";
            cin >> guess;
            tries++;

            if (guess == "quit") {
                isQuit = true;
                break;
            }

            if (guess != word) cout << "Incorrect! Try again!" << endl;
            else {
                cout << "Correct! You guessed the word in " << tries 
                    << " tries. Want to play again? (y/n)" << endl;
                char decision;
                cin >> decision;

                switch (decision) {
                    case 'y':
                        break;

                    case 'n':
                        isQuit = true;
                        break;
                }
            }
        }
    }

    return 0;
}

string encrypt(string str) {

    //encrypt vowels with underscores
    char Vowels[5] = { 'a', 'e', 'o', 'u', 'i' };

    for (char& ch : str) {
        for (char v : Vowels) {
            ch = (ch == v) ? '_' : ch;
        }
    }

    return str;
}
