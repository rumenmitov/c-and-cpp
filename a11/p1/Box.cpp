/* 
   CH-230-A 
   a11_p1.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include "Box.h"

Box::Box() {
    this->height = 0;
    this->width = 0;
    this->depth = 0;
}

Box::Box(const double& height, const double& width, const double& depth) {
    this->height = height;
    this->width = width;
    this->depth = depth;
}

Box::Box(const Box& box) {
    this->height = box.height;
    this->width = box.width;
    this->depth = box.depth;
}

// NOTE destructor is empty because we have nothing to free
Box::~Box() {}

void Box::setHeight(const double& height) { this->height = height; }
void Box::setWidth(const double& width) { this->width = width; };
void Box::setDepth(const double& depth) { this->depth = depth; };

double Box::getHeight() const { return this->height; }
double Box::getWidth() const { return this->width; }
double Box::getDepth() const { return this->depth; }
