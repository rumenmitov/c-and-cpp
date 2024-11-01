/* 
   CH-230-A 
   a12_p3.h
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
        virtual ~TournamentMember();

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
        virtual void print();
        static void change_location(const std::string&);

    private:
        char fname[36];
        char lname[36];
        char dob[11];

        static std::string location;

        std::string nationality;
        float height; // in metres

};

class Player : public TournamentMember {

    public:
        // constructors and destructors
        Player();
        Player
            (const char*, const char*, const char*, 
             const std::string&, float, int, 
             const std::string&, int, const std::string&);

        Player(const Player&);
        ~Player() override;

        // getters and setters
        int get_number() { return number; }
        std::string get_position() { return position; }
        int get_goals() { return goals; }
        std::string get_footed() { return footed; }

        void set_number(int number) { this->number = number; }
        void set_position(const std::string& position) { 
            this->position = position;
        }
        void set_goals(int goals) { this->goals = goals; }
        void set_footed(const std::string& footed) { this->footed = footed; }

        // methods
        void print() override;
        void increment_goals();
        

    private:
        int number;
        std::string position;
        int goals;
        std::string footed;
    
};

#endif
