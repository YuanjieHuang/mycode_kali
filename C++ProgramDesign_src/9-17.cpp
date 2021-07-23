#include <iostream>
using namespace std;
class POINT { 
public:  	
	POINT(int x1, int y1)   
	{	
        x = new int;
        y = new int;
		*x = x1; 	
		*y = y1;
		cout<<"Constructing Point\n"; 
	} 
	POINT(POINT& anoP)  
	{	
        x = new int;
        y = new int;
      	*x = *anoP.x;
		*y = *anoP.y;
		cout<<"Copy Constructing Point\n";
	}   
    ~POINT( ) 
    {	
		cout<<"Destructing Point\n";
		if(x !=NULL) delete x;
		if(y!=NULL) delete y;
	}
	int get_x( )   
	{	
		return *x;
    }
    int get_y( )
    {	
		return *y;
    }
private:
    int *x ;
    int *y ;
};
void print( POINT obj)
{	
	cout << "Point: (" <<obj. get_x() << ", " << obj.get_y() << ")" << endl;    
}
int main()
{
    POINT  point1(2,3);
    POINT  point2(point1);
    print(point1);   
}
