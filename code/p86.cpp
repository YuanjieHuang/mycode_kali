void fib(int n)
{
    int prev, now, next, j;
    if (n <= 1) return(n);
    else  {
        prev = 0;
        now = 1;
        for (j = 2; j <= n; j++)  {
            next = prev + now;
            prev = now;
            now = next;
        }
        return(next);
    }
}
