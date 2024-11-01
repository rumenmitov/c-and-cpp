/* 
   CH-230-A 
   a11_p6.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <cmath>
#include <iostream>

#include "Vector.h"

Vector::Vector() : Size(1) {
    Elements = new double[Size]{};
}

Vector::Vector(int size, const double*& elements) : Size(size) {
    Elements = new double[Size];
    
    for (int i = 0; i < Size; ++i) {
        Elements[i] = elements[i];
    }
}

Vector::Vector(const Vector& v) : Size(v.Size) {
    Elements = new double[Size];

    for (int i = 0; i < Size; ++i) {
        Elements[i] = v.Elements[i];
    }
}

Vector::~Vector() {
    delete [] Elements;
}


int Vector::getSize() const { return Size; }
double* Vector::getElements() const { return Elements; }
void Vector::setSize(int n) { 
    // create new array with size n
    double* arr = new double[n];

    // paste as many elements as can fit from old array
    for (int i = 0; i < (Size < n ? Size : n); ++i) {
        arr[i] = Elements[i];
    }

    // update size
    Size = n;

    delete [] Elements;
    Elements = arr;
}

void Vector::setElements(int size, const double* elements) {
    Size = size;

    double* arr = new double[Size];

    for (int i = 0; i < Size; ++i) {
        arr[i] = elements[i];
    }

    delete [] Elements;

    Elements = arr;
}

void Vector::print() {
    for (int i = 0; i < Size; ++i) {
        std::cout << Elements[i] << " ";
    }

    std::cout << std::endl;
}

double Vector::norm() {
    double res = 0;

    for (int i = 0; i < Size; ++i) {
        res += Elements[i] * Elements[i];
    }

    res = std::sqrt(res);

    return res;
}

/* NOTE
 * Both vectors must be of same dimensions.
 */

Vector Vector::add(const Vector v) const {
    Vector res(*this);
    double* arr = new double[Size]{};
    for (int i = 0; i < Size; ++i) {
        arr[i] = Elements[i] + v.Elements[i];
    }

    res.setElements(Size, arr);

    return res;
}

Vector Vector::subtract(const Vector v) const {
    Vector res(*this);
    double* arr = new double[Size]{};
    for (int i = 0; i < Size; ++i) {
        arr[i] = Elements[i] - v.Elements[i];
    }

    res.setElements(Size, arr);

    return res;
}

double Vector::scalar_product(const Vector v) const {
    double res;

    for (int i = 0; i < Size; ++i) {
        res += Elements[i] * v.Elements[i];
    }
    return res;
}
