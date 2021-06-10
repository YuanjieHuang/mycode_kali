程序清单8-10
#include <iostream> 
using namespace std;

class Window { 
public: 
    Window( ) 
    { 
        count = count + 1; 
    } 

    ~Window( ) 
    { 
        count = count - 1; 
    } 

    int getWin( ) 
    { 
        return count; 
    } 
private: 
    static int count; 
}; 

int Window::count = 0; 

class WorkWindow: public Window { 
public: 
    WorkWindow( ) 
    { 
        cout << "Open a work window" << endl; 
    } 

    ~WorkWindow( ) 
    { 
        cout << "Close a work window" << endl; 
    } 
}; 

class MsgWindow: public Window { 
public: 
    MsgWindow( ) 
    { 
        cout << "Open a message window" << endl; 
    } 

    ~MsgWindow( ) 
    { 
        cout << "Close a message window" << endl; 
    } 
}; 

class Screen { 
public: 
    Screen( ): msgWin( ), workWin( ) 
    { 
        cout << "Initialize the screen" << endl; 
    } 

    ~Screen( ) 
    { 
        cout << "Clear the screen" << endl; 
    } 

    int getWin( ) 
    { 
        return workWin.getWin( ); 
    } 
private: 
    WorkWindow workWin; 
    MsgWindow msgWin; 
}; 

int main( ) 
{ 
    Screen screen; 
    Window msgWin; 

    cout << "There are " << screen.getWin( ) << " Window(s) on screen" << endl; 
cout << "There are " << msgWin.getWin( ) << " message Window(s)" << endl; 

    return 0; 
} 
