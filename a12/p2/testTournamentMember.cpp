/* 
   CH-230-A 
   a12_p2.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <string>

#include "TournamentMember.h"

int main(void) {

    TournamentMember::change_location("Hawaii");
    TournamentMember t1;
    TournamentMember t2("Carlos", "Smith", "1999-02-12", "Germany", 2.01);
    TournamentMember t2_copy(t2);

    t2_copy.set_fname("Davonte");
    t2_copy.set_lname("Green");

    std::cout << std::endl;

    t1.print();
    t2.print();
    t2_copy.print();

    return 0;
}
