程序清单6-12
void swap( int *p1, int *p2 )
{
    int *p;
	
    p = p1;
    p1 = p2;
    p2 = p;
}

int main()
{
    int a = 4, b = 5;
    int *p1, *p2;

    p1 = &a;
    p2 = &b;

    if(a < b) swap( p1, p2 );

    cout << "max = " << *p1 << "  "<< "min = " << *p2;
}
