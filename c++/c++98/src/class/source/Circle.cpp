class Circle {
protected:
    double radius;
public:
    Circle(double r = 0) {radius = r;}
    double getr() {return radius;}
    double area() { return 3.14 * radius * radius; }
    double circum() { return 2 * 3.14 * radius;}
};

#include <iostream>
using namespace std;


class Ball:public Circle {
public: 
    Ball(double r = 0):Circle(r) {}
    double area() { return 4 * 3.14 * radius * radius; }
    double volumn() { return 4 * 3.14 * radius * radius * radius / 3; }
};

class Cylinder:public Circle {
    double height; 
public:
    Cylinder(double r = 0, double h = 0):Circle(r) {height = h;}
    double geth() {return height;}
    double area() { return 2 * Circle::area() + circum() * height; }
    double volumn() { return Circle::area() * height ; }
};

int main()
{   Circle c(3);
    Ball b(2);
    Cylinder cy(1,2);

    cout << "circle: r=" << c.getr() << endl;
    cout << "area=" << c.area() << "\tcircum=" << c.circum() << endl;

    cout << "ball: r=" << b.getr() << endl;
    cout << "area=" << b.area() << "\tvolumn=" << b.volumn() << endl;

    cout << "cylinder: r=" << cy.getr() << "\th = " << cy.geth() << endl;
    cout << "area=" << cy.area() << "\tvolumn=" << cy.volumn() << endl;
 
    return 0;
}