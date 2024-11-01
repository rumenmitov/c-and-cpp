/* 
   CH-230-A 
   a9_p2.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <string>

int main(void) {

    // get user input
    int n;
    double x;
    std::string s;

    std::cin >> n;
    std::cin >> x;
    std::cin >> s;

    // print result n times
    for (int i = 0; i < n; ++i) {
        std::cout << s << ":" << x << std::endl;
    }

    return 0;
}
