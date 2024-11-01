/* 
   CH-230-A 
   a11_p5.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

// please refer to shapes.h for methods documentation

#include <cmath>
#include <iostream>
#include <string>
#include "Shapes.h"

using namespace std; 

Shape::Shape(const string& n) : name(n) {
}

// adding default constructor for shape
Shape::Shape() { name = ""; }

// copy constructor for shape
Shape::Shape(const Shape& s) : name(s.name) {}

void Shape::printName() const {
	cout << name << endl;
}

// getters for shape
std::string Shape::getName() const { return name; }

// setters for shape
void Shape::setName(const std::string& name) { this->name = name; }

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

// adding default constructor for centered shape
CenteredShape::CenteredShape() {
    // name is set using default shape constructor
    x = 0;
    y = 0;
}

// copy constructor for centered shape
CenteredShape::CenteredShape(const CenteredShape& s) : 
    Shape(s.getName()), x(s.x), y(s.y) {}

// getters for centered shape
double CenteredShape::getX() const { return x; }
double CenteredShape::getY() const { return y; }

// setters for centered shape
void CenteredShape::move(double x, double y) {
    this->x = x;
    this->y = y;
}
void CenteredShape::setX(double x) { this->x = x; }
void CenteredShape::setY(double y) { this->y = y; }

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) {
	EdgesNumber = nl;
}

// adding default constructor for regular polygon
RegularPolygon::RegularPolygon() {
    // default centered shape is called automagically

    /* NOTE
     * The least amount of edges a regular polygon can have is 3.
     */
    EdgesNumber = 3;
}

// copy constructor for regular polygon
RegularPolygon::RegularPolygon(const RegularPolygon& s) :
    CenteredShape(s.getName(), s.getX(), s.getY()), 
    EdgesNumber(s.EdgesNumber) {}

// getters for regular polygon
int RegularPolygon::getEdges() const { return EdgesNumber; }

// setters for regular polygon 
void RegularPolygon::setEdges(int n) { EdgesNumber = n; }

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) {
	Radius = r;
}

// adding default constructor for circle
Circle::Circle() {
    // default centered shape is called automagically
    Radius = 1;
}

// copy constructor for circle
Circle::Circle(const Circle& s) : CenteredShape(s.getName(), s.getX(), s.getY()), 
    Radius(s.Radius) {}

// getters for circle
double Circle::getRadius() const { return Radius; }

// setters for circle
void Circle::setRadius(double r) { Radius = r; }

double Circle::perimeter() const { return 2 * M_PI * Radius; }
double Circle::area() const { return M_PI * Radius * Radius; }

#define RECT_EDGES 4

Rectangle::Rectangle() {
    width = 1;
    height = 1;
}

Rectangle::Rectangle(const string& n, double nx, double ny, double nwidth,
        double nheight) : RegularPolygon(n, nx, ny, RECT_EDGES) {

    width = nwidth;
    height = nheight;
}

Rectangle::Rectangle(const Rectangle& s) : 
    RegularPolygon(s.getName(), s.getX(), s.getY(), s.getEdges()), 
    width(s.width), height(s.height) {}

// getters for rectangle
double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return height; }

// setters for rectangle
void Rectangle::setWidth(double width) { this->width = width; }
void Rectangle::setHeight(double height) { this->height = height; }

double Rectangle::perimeter() const { return (width + height) * 2; }
double Rectangle::area() const { return width * height; }

Square::Square() : Rectangle("square", 0, 0, 1, 1) {
    side = 1;
}

Square::Square(const std::string& n, double nx, double ny, double nside) :
    Rectangle(n, nx, ny, nside, nside) {}

Square::Square(const Square& s) : 
    Rectangle(s.getName(), s.getX(), s.getY(), s.side, s.side) {}

// getters for square
double Square::getSide() const { return side; }

// setters for square
void Square::setSide(double side) { this->side = side; }
