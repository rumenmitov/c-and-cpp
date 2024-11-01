/* 
   CH-230-A 
   a12_p3.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

#include "TournamentMember.h"

int main(void) {

    Player* p1 = new Player;
    p1->set_position("Defender");

    Player* p2 = new Player
        ("Joe", "Smith", "1990-10-23", "England", 1.90, 5, "Goalkeeper",
         0, "left");

    Player* p2_copy = new Player(*p2);

    p2_copy->set_position("Forward");
    p2_copy->increment_goals();

    TournamentMember::change_location("Hamburg");

    std::cout << std::endl;

    p1->print();
    p2->print();
    p2_copy->print();

    delete p1;
    delete p2;
    delete p2_copy;
    return 0;
}
