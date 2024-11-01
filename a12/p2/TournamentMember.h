/* 
   CH-230-A 
   a12_p2.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef __TOURNAMENTMEMBER_H
#define __TOURNAMENTMEMBER_H

#include <cstring>
#include <string>
class TournamentMember {

    public:
        // constructors and destructos
        TournamentMember();
        TournamentMember
            (const char*, const char*, const char*, const std::string&, float);

        TournamentMember(const TournamentMember&);
        ~TournamentMember();

        // getters and setters
        const char* get_fname() const { return fname; }
        const char* get_lname() const { return lname; }
        const char* get_dob() const { return dob; }
        std::string get_location() const { return location; }
        std::string get_nationality() const { return nationality; }
        float get_height() const { return height;}

        void set_fname(const char* fname) {
            strncpy(this->fname, fname, 36);
            this->fname[35] = '\0';
        }

        void set_lname(const char* lname) {
            strncpy(this->lname, lname, 36);
            this->lname[35] = '\0';
        }

        void set_dob(const char* dob) {
            strncpy(this->dob, dob, 36);
            this->dob[10] = '\0';
        }

        void set_nationality(const std::string& nationality) {
            this->nationality = nationality;
        }

        void set_height(float height) {
            this->height = height;
        }

        // methods
        void print();
        static void change_location(const std::string&);

    private:
        char fname[36];
        char lname[36];
        char dob[11];

        static std::string location;

        std::string nationality;
        float height; // in metres
};

#endif
