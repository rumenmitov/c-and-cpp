/* 
   CH-230-A 
   a9_p6.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <cctype>
#include <iostream>

using namespace std;

int myfirst(const int* arr, int size);
double myfirst(const double* arr, int size);
char myfirst(const char* arr, int size);


int main(void) {

    // get user input
    int size_int, size_double, size_char;

    cout << "Enter size of integer array: ";
    cin >> size_int;
    cout << endl;

    int* arr_int = new int[size_int];
    for (int i = 0; i < size_int; ++i) {
        cout << "Enter integer: ";
        cin >> arr_int[i];
    }
    cout << endl;
    
    cout << "Enter size of double array: ";
    cin >> size_double;
    cout << endl;

    double* arr_double = new double[size_double];
    for (int i = 0; i < size_double; ++i) {
        cout << "Enter double: ";
        cin >> arr_double[i];
    }
    cout << endl;

    cout << "Enter size of char array: ";
    cin >> size_char;
    cout << endl;

    char* arr_char = new char[size_char];
    for (int i = 0; i < size_char; ++i) {
        cout << "Enter char: ";
        cin >> arr_char[i];
    }
    cout << endl;

    // print results
    cout << "Result of integer array: " << myfirst(arr_int, size_int) << endl;
    cout << "Result of double array: " 
        << myfirst(arr_double, size_double) << endl;
    cout << "Result of char array: " << myfirst(arr_char, size_char) << endl;

    // free memory
    delete [] arr_int;
    delete [] arr_double;
    delete [] arr_char;

    return 0;
}

int myfirst(const int* arr, int size) {
    int index = -1;

    // check for first positive even number
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0 && arr[i] % 2 == 0) {
            index = i;
            break;
        }
    }

    return index;

}

double myfirst(const double* arr, int size) {
    double index = -1.1;

    for (int i = 0; i < size; ++i) {
        // check for fractional part by removing non-fractional part

        if (arr[i] - static_cast<int>(arr[i]) == 0.0) {
            index = i;
            break;
        }
    }

    return index;
}

char myfirst(const char* arr, int size) {
#define VOWELS_SIZE 11

    const char Vowels[VOWELS_SIZE] = {'a', 'e', 'o', 'u', 'i', ' ', '\n', ',',
        '.', '\t', '\0'};

    char el = '0';

    // check for first consonant
    for (int i = 0; i < size; ++i) {
        bool isVowel = false;
        for (int j = 0; j < VOWELS_SIZE; ++j) {
            if (tolower(arr[i]) == Vowels[j]) {
                isVowel = true;
                break;
            }
        }

        if (!isVowel) {
            el = arr[i];
            break;
        }
    }

    return el;
}
