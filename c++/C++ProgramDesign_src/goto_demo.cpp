#include <iostream>
using namespace std;
int main()
{
    int n;
    int i;
    int f;
    i=1;
    f=1;
    cout << "Please input an integer number: " << endl;
    cin >> n;
Fctor:
    f=f*i;
    i++;
    if (i<=n) 
goto Fctor;
    cout << "Factorial of " << n << "=" << f << endl;
    return 0;
}
