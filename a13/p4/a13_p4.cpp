/* 
   CH-230-A 
   a13_p4.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include<iostream>
using namespace std;

class A {
    //adding private label for readability
    private:
        int x;
    public:
        void setX(int i) {x = i;}
        void print() { cout << x; }
};

// setting inheritance to virtual to prevent ambiguity in class D by 
// ensuring that only the subobject will be created
class B:  virtual public A {
    public:
        B()  { setX(10); }
};

// setting inheritance to virtual to prevent ambiguity in class D by
// ensuring that only the subobject will be created
class C:  virtual public A  {
    public:
        C()  { setX(20); }
};

class D: public B, public C {
    public:
        // adding default constructor to D, so that we can set the x property
        D() { setX(30); }
};

int main() {
    D d;
    d.print();
    return 0;
}

/* Explanation
 * The call to print is ambiguous because class D inherits from 
 * the classes and B and C which inherit the x property from the class A.
 * Since B and C set their respective x properties to different values during
 * their default constructors, the compiler does not know which x to print.
 */
