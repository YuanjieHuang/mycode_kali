#include <iostream>
using namespace std;

int f(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return f(n-3) + f(n-2) + f(n-1);
}

// int f(const int n)
// {
//     return 0;
// }

void printFooSeq(int n)
{
    int fi_1 = 1, fi_2 = 1, fi_3 = 1, fi = 0;
    for(int i = 2; i <= n; i++)
    {
        fi = fi_1 + fi_2 + fi_3;
        fi_3 = fi_2;
        fi_2 = fi_1;
        fi_1 = fi;
        cout<<fi<<" ";
    }
}

void diff_sizeof_strlen(char str[100])
{
    cout<<"sizeof "<<sizeof(str)<<endl;
    cout<<"strlen "<<strlen(str)<<endl;
}
int main()
{
    char str[100] = "hello world";
    char *s = "hello world";

    cout<<sizeof(str)<<endl;
    cout<<strlen(s)<<endl;
    diff_sizeof_strlen(str);
    cout<<f(4)<<endl;
    printFooSeq(5);
    return 0;
}