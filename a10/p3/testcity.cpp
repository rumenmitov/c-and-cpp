/* 
   CH-230-A 
   a10_p3.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <cstdio>
#include <iostream>
#include <string>

#include "City.h"

using namespace std;

int main(void) {

    City London("London"), Paris("Paris"), Bremen("Bremen");

    int32_t population;
    string mayor;
    int area;

    // get inputs and instantiate classes
    cout << "Enter London's population: ";
    cin >> population;
    London.setPopulation(population);
    getchar();
    cout << "Enter London's mayor: ";
    getline(cin, mayor);
    London.setMayor(mayor);
    cout << "Enter London's area: ";
    cin >> area;
    London.setArea(area);

    cout << "Enter Paris's population: ";
    cin >> population;
    getchar();
    Paris.setPopulation(population);
    cout << "Enter Paris's mayor: ";
    getline(cin, mayor);
    Paris.setMayor(mayor);
    cout << "Enter Paris's area: ";
    cin >> area;
    Paris.setArea(area);
    
    cout << "Enter Bremen's population: ";
    cin >> population;
    getchar();
    Bremen.setPopulation(population);
    cout << "Enter Bremen's mayor: ";
    getline(cin, mayor);
    Bremen.setMayor(mayor);
    cout << "Enter Bremen's area: ";
    cin >> area;
    Bremen.setArea(area);

    cout << endl;

    // print output
    cout << "London Info:" << endl;
    cout << "Name - " << London.getName() << endl;
    cout << "Population - " << London.getPopulation() << endl;
    cout << "Mayor - " << London.getMayor() << endl;
    cout << "Area - " << London.getArea() << endl;

    cout << endl;

    cout << "Paris Info:" << endl;
    cout << "Name - " << Paris.getName() << endl;
    cout << "Population - " << Paris.getPopulation() << endl;
    cout << "Mayor - " << Paris.getMayor() << endl;
    cout << "Area - " << Paris.getArea() << endl;

    cout << endl;

    cout << "Bremen Info:" << endl;
    cout << "Name - " << Bremen.getName() << endl;
    cout << "Population - " << Bremen.getPopulation() << endl;
    cout << "Mayor - " << Bremen.getMayor() << endl;
    cout << "Area - " << Bremen.getArea() << endl;

    return 0;
}
