/* 
   CH-230-A 
   a12_p3.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <cstring>
#include <iostream>
#include <string>

#include "TournamentMember.h"

std::string TournamentMember::location; // initializing static variable

TournamentMember::TournamentMember() {
    strcpy(fname, "");
    strcpy(lname, "");
    strcpy(dob, "0000-00-00");
    nationality = "";
    height = 0.0;

    std::cout << "Default constructor called.\n";
}

TournamentMember::TournamentMember 
    (const char* fname, const char* lname, const char* dob, 
     const std::string& nationality, 
     float height) : nationality(nationality), height(height) {

    strncpy(this->fname, fname, 36);
    strncpy(this->lname, lname, 36);
    strncpy(this->dob, dob, 11);

    std::cout << "Parametric constructor called.\n";
}

TournamentMember::TournamentMember(const TournamentMember& t) :
    nationality(t.nationality), height(t.height) {

    strncpy(this->fname, t.fname, 36);
    strncpy(this->lname, t.lname, 36);
    strncpy(this->dob, t.dob, 11);

    std::cout << "Copy constructor called.\n";
}

TournamentMember::~TournamentMember() {
    // NOTE: no need for freeing memory as all of it is in the stack

    std::cout << "Destructor called.\n";
}


void TournamentMember::print() {
    std::cout << "Tournament Member info:\n";
    std::cout << "First name: " << fname << std::endl;
    std::cout << "Last name: " << lname << std::endl;
    std::cout << "Date of Birth: " << dob << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Nationality: " << nationality << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << std::endl;
}

void TournamentMember::change_location(const std::string& nlocation) {
    location = nlocation;
}

Player::Player() {
    number = -1;
    position = "";
    goals = 0;
    footed = "";

    std::cout << "Default Player constructor called.\n";
}

Player::Player 
    (const char* fname, const char* lname, const char* dob, 
     const std::string& nationality, float height, int number, 
     const std::string& position, int goals, const std::string& footed) : 
     TournamentMember(fname, lname, dob, nationality, height), number(number),
     position(position), goals(goals), footed(footed) {


        std::cout << "Parametric Player constructor called.\n";
}

Player::Player(const Player& p) : TournamentMember(p.get_fname(),
        p.get_lname(), p.get_dob(), p.get_nationality(), p.get_height()),
        number(p.number), position(p.position), goals(p.goals), 
        footed(p.footed) {


        std::cout << "Copy Player constructor called.\n";
}

Player::~Player() {
    std::cout << "Player destroyed.\n";
}

void Player::print() {
    std::cout << "Tournament Member info:\n";
    std::cout << "First name: " << get_fname() << std::endl;
    std::cout << "Last name: " << get_lname() << std::endl;
    std::cout << "Date of Birth: " << get_dob() << std::endl;
    std::cout << "Location: " << get_location() << std::endl;
    std::cout << "Nationality: " << get_nationality() << std::endl;
    std::cout << "Height: " << get_height() << std::endl;
    std::cout << "Number: " << number << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Goals scored: " << goals << std::endl;
    std::cout << "Favoured foot: " << footed << std::endl;
    std::cout << std::endl;
}

void Player::increment_goals() { goals++; }
