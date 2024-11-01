/* 
   CH-230-A 
   a10_p3.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <string>

#include "City.h"

City::City(std::string name) { this->name = name; }

std::string City::getName() { return name; }

int64_t City::getPopulation() { return population; }

std::string City::getMayor() { return mayor; }

int City::getArea() { return area; }

void City::setName(std::string new_name) { this->name = new_name; }

void City::setPopulation(int64_t new_population) {
    this->population = new_population;
}

void City::setMayor(std::string new_mayor) { this->mayor = new_mayor; }

void City::setArea(int new_area) { this->area = new_area; }
