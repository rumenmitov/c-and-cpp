/* 
   CH-230-A 
   a9_p4.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <cstdio>
#include <iostream>
#include <string>

int mycount(int n1, int n2);
int mycount(char ch, std::string str);

int main(void) {

    // get user input
    int n1, n2;
    char ch;
    std::string str;

    std::cout << "Enter two integers:" << std::endl;
    std::cin >> n1;
    std::cin >> n2;

    std::cout << "Enter a character:" << std::endl;
    std::cin >> ch;

    std::cout << "Enter string:\n";
    getchar();
    std::getline(std::cin, str);

    // print results
    std::cout << "Result of integers: " << mycount(n1, n2) << std::endl;
    std::cout << "Result of string: " << mycount(ch, str) << std::endl;
    return 0;
}

int mycount(int n1, int n2) {
    return n1 - n2;
}

int mycount(char ch, std::string str) {
    int count = 0;

    for (char c : str) {
        if (ch == c) count++;
    }

    return count;
}
