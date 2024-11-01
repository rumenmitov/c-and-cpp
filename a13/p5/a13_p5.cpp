/* 
   CH-230-A 
   a13_p5.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include<iostream>
using namespace std;

class A {
    private:
        int x;
    public:
        A(int i) { x = i; }
        void print() { cout << x; }
};

class B: virtual public A {
    public:
        B():A(10) {  }
};

class C:  virtual public A {
    public:
        C():A(10) {  }
};

class D: public B, public C {
    // adding public constructor that will initialize the parent classes 
    public:
        D() : A(10), B(), C() { }
};

int main()
{
    D d;
    d.print();
    return 0;
}

/* 
 * Explanation
 * Since the inheritance of B and C is virtual, their constructors must be
 * explicitly called when a subobject of class D is created.
 *
 * After the modifications D will call each parent constructor and it 
 * will have only one value for x.
 */
