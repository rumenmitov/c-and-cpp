/* 
   CH-230-A 
   a11_p5.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

/* 
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>

class Shape {			// base class
	private:   				// private access modifier: could also be protected
		std::string name;   // every shape will have a name
	public:
		Shape(const std::string&);  // builds a shape with a name
		Shape();					// empty shape
		Shape(const Shape&);		// copy constructor
		void printName() const ;  	// prints the name  

        // getters
        std::string getName() const;

        // setters
        void setName(const std::string&);
};

class CenteredShape : public Shape {  // inherits from Shape
	private: 
		double x,y;  // the center of the shape
	public:
		CenteredShape(const std::string&, double, double);  // usual three constructors
		CenteredShape();
		CenteredShape(const CenteredShape&);
		void move(double, double);	// moves the shape, i.e. it modifies it center

        // getters
        double getX() const;
        double getY() const;

        // setters
        void setX(double);
        void setY(double);
};

class RegularPolygon : public CenteredShape { // a regular polygon is a centered_shape with a number of edges
	private: 
		int EdgesNumber;
	public:
		RegularPolygon(const std::string&, double, double, int);
		RegularPolygon();
		RegularPolygon(const RegularPolygon&);

        // getters
        int getEdges() const;

        // setters
        void setEdges(int);
};

class Circle : public CenteredShape {  // a Circle is a shape with a center and a radius
	private:
		double Radius;
	public:
		Circle(const std::string&, double, double, double);
		Circle();
		Circle(const Circle&);

        // getters
        double getRadius() const;

        // setters 
        void setRadius(double);

        double perimeter() const;
        double area() const;
};

// rectangle and square classes
class Rectangle : public RegularPolygon {
    private:
        double width;
        double height;

    public:
        Rectangle();
        Rectangle(const std::string&, double, double, double, double);
        Rectangle(const Rectangle&);

        // getters
        double getWidth() const;
        double getHeight() const;

        // setters
        void setWidth(double);
        void setHeight(double);

        double perimeter() const;
        double area() const;
};

class Square : public Rectangle {
    private:
        double side;
    public:
        Square();
        Square(const std::string&, double, double, double);
        Square(const Square&);

        // getters
        double getSide() const;

        // setters 
        void setSide(double);

        /* NOTE
         * Square does not need perimeter and area methods, 
         * because it inherits them from Rectangle
         */
};
    
#endif
