/* 
   CH-230-A 
   a10_p3.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef CITY_H
#define CITY_H

#include <cstdint>
#include <string>

class City {
    private:
        std::string name;
        /* NOTE:
         * City population is in the millions, hence I used a 32-integer.
         */
        int32_t population;
        std::string mayor;
        int area;

    public:
        City(std::string);

        // getters
        std::string getName();
        int64_t getPopulation();
        std::string getMayor();
        int getArea();

        // setters
        void setName(std::string);
        void setPopulation(int64_t);
        void setMayor(std::string);
        void setArea(int);
};


#endif
