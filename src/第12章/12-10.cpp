　　class Ball:public Circle {
　　public: 
　　    Ball(double r = 0):Circle(r) {}
　　    double area() { return 4 * 3.14 * radius * radius; }
　　    double volumn() { return 4 * 3.14 * radius * radius * radius / 3; }
　　};
　　
