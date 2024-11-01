/* 
   CH-230-A 
   a12_p1.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

// please refer to shapes.h for methods documentation

#include <cmath>
#include <iostream>
#include "Shapes.h"

using namespace std; 

Shape::Shape() {}

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << name << endl;
}

CenteredShape::CenteredShape() {}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

RegularPolygon::RegularPolygon() {}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) {

	EdgesNumber = nl;
}

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) {

	Radius = r;
}

Hexagon::Hexagon(int side, const string& color) : side(side), color(color) {}

Hexagon::Hexagon(const Hexagon& h) : side(h.side), color(h.color) {}

Hexagon::~Hexagon() {}

int Hexagon::perimeter() const { return HEXAGON_EDGES * side; }

int Hexagon::area() const { return 3 * std::sqrt(3) * side * side / 2; }
