/* 
   CH-230-A 
   a11_p6.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef __VECTOR_H
#define __VECTOR_H

class Vector {
    public:
        // constructors
        Vector();
        Vector(int, const double*&);
        Vector(const Vector&);

        // destructor
        ~Vector();

        // setters and getters
        int getSize() const;
        double* getElements() const;
        void setSize(int n);
        void setElements(int, const double*);

        // other methods
        void print();
        double norm();
        /* NOTE
         * Omitting pass-by-reference for addition as the prototype
         * provided omitted it as well.
         */
        Vector add(const Vector) const;
        Vector subtract(const Vector) const;
        double scalar_product(const Vector) const;


    private:
        int Size;
        double* Elements;
};

#endif
