/* 
   CH-230-A 
   a9_p8.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

using namespace std;

void subtract_max(int*& arr, int size);
void deallocate(int*& arr);

int main(void) {

    // get input
    int n;
    cin >> n;

    // create array and insert values
    int* a = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // remove max value
    subtract_max(a, n);

    // print result
    for (int i = 0; i < n-1; ++i) {
        cout << a[i] << endl;
    }

    // free memory
    deallocate(a);

    return 0;
}

void subtract_max(int*& arr, int size) {

    /* NOTE:
     * I am assuming that I only have to remove one value,
     * even if there are multiple elements that are maximums.
     */

    // find max
    int max = *arr;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) max = arr[i];
    }

    // subtract max from original array
    int* new_arr = new int[size-1];

    bool hasMaxBeenRemoved = false;

    for (int i = 0; i < size; ++i) {
        if (!hasMaxBeenRemoved) {
            if (arr[i] == max) {
                hasMaxBeenRemoved = true;
                continue;
            } else {
                new_arr[i] = arr[i];
            }
        } else {
            new_arr[i-1] = arr[i];
        }
    }

    // swap array
    arr = new_arr;
}

void deallocate(int*& arr) {
    delete []arr;
}
