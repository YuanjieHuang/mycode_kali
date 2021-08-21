#include <string>
#include <iostream>

using namespace std;

int while1 ()
{
	string password;
	while ( 1 )
	{
		cout << "Please enter your password: ";
		cin >> password;
		if ( password == "foobar" )
		{
			break;
		}
	}
	cout << "Welcome, you got the password right";
}

int main ()
{
	string password;
	do
	{
		cout << "Please enter your password: ";
		cin >> password;
	} while ( password != "foobar" );
	cout << "Welcome, you got the password right";
}
