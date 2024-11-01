/* 
   CH-230-A 
   a13_p6.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <vector>

int main(void) {

    // creating vector
    std::vector<int> v;
    for (int i = 0; i < 20; i++) v.push_back(8); 
    
    // trying to access 21st element, if not possible catch error
    try {
        std::cout << v.at(21) << std::endl;

    } catch(const std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    return 0;
}
