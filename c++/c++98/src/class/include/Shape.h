class Shape{
protected: 
    double x, y;
public: 
    Shape(double xx, double yy) {x=xx; y=yy;}
    virtual double area()  {return 0.0;}
    virtual void display() 
        {cout << "This is a shape. The position is (" << x << ", " << y << ")\n";}
};

class Rectangle:public Shape {
protected:
    double w, h;
public: 
    Rectangle(double xx, double yy, double ww, double hh): Shape(xx,yy),w(ww),h(hh){}
    double area()    {return w * h;} //重定义虚函数area
    void display()   //重定义虚函数display
    {   cout << "This is a rectangle. The position is (" << x << ", " << y << ")\t";
        cout << "The width is " << w << ". The height is " << h << endl;
    }
};

class Circle:public Shape {
protected:
    double r;
public: 
    Circle(double xx, double yy, double rr): Shape(xx,yy),r(rr){}
    double area()    {return 3.14 * r * r;}
    void display() 
    {   cout << "This is a rectangle. The position is (" << x << ", " << y << ")\t";
        cout << "The radius is " << r << endl;
    }
};