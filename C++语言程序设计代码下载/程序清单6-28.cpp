程序清单6-28
#include< iostream >
using namespace std;

void fun(); 

int main()
{
    fun();
    fun();
    fun();
    
    return 0;
}

void fun()
{
    static int A[3]={ 1, 2, 3 };
    int  B[3]={ 1, 2, 3 };
    int i;
  
    for ( i = 0; i < 3; i++ ){
        A[i]++;
        cout << "A[" << i << "]=" << A[i] << endl;
    }

    for ( i = 0; i < 3; i++ ){
        B[i]++;
        cout << "B[" << i << "]=" << B[i] << endl;    
    }  
  
    cout << "-----------------------------------" << endl;
}
