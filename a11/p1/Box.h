/* 
   CH-230-A 
   a11_p1.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef BOX_H
#define BOX_H

class Box {
    private: 
        double height;
        double width;
        double depth;

    public:
        // constructors
        Box();
        Box(const double&, const double&, const double&);

        // copy constructor
        Box(const Box&);

        // destructor
        ~Box();

        // setters
        void setHeight(const double&);
        void setWidth(const double&);
        void setDepth(const double&);

        // getters
        double getHeight() const;
        double getWidth() const;
        double getDepth() const;
};


#endif
