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
　　
