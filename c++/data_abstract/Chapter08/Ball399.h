#include "Sphere399.h"#include <string>using namespace std; class Ball: public Sphere{public:  // everything as before, except  // displayStatistics is omitted  // and getArea is virtual:// constructors:   Ball();   Ball(double initialRadius,        const string initialName);   // Creates a ball with radius initialRadius and   // name initialName.// additional or revised operations:   void getName(string currentName) const;   // Determines the name of a ball.   void setName(const string newName);   // Sets (alters) the name of an existing ball.   void resetBall(double newRadius,                  const string newName);   // Sets (alters) the radius and name of an existing   // ball to newRadius and newName, respectively.   virtual double getArea() const; // cross-sectional areaprivate:   string theName; // the ball's name}; // end class