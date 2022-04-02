int divide(int dividend, int divisor)
{
    int sign = (dividend ^ divisor)>>31 & 0x1 == 1? -1:1;
    long result = 0;
    long d1 = abs((long)dividend), d2 = abs((long)divisor);
    while (d1 >= d2)
    {
        d1 -= d2;
        result++;
    }
    result *= sign;
    if(result > INT_MAX || result < INT_MIN)
    {
        return INT_MAX;
    }
    return (int)result;
}

int divide(int dividend, int divisor)
{
    int sign = (dividend ^ divisor)>>31 & 0x1 == 1? -1:1;
    long result = 0;
    long d1 = abs((long)dividend), d2 = abs((long)divisor);
    while (d1 >= d2)
    {
        long i = 1;
        long tmp = d2;
        while (d1 >= tmp)
        {
            d1 -= tmp;
            result += i;
            i = i<<1;
            tmp = tmp <<i;
        }
        
    }
    result *= sign;
    if(result > INT_MAX || result < INT_MIN)
    {
        return INT_MAX;
    }
    return (int)result;
}