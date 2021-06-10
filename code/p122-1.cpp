void bmPreprocess1()
{
    int i = m, j = m + 1;
    f[i] = j;
    while (i > 0){
        while (j <= m && p[i-1] !=p[j-1])  {
            if (s[j] == 0) s[j] = j-i;
            j = f[j];
        }
        i--;
        j--;
        f[i] = j;
    }
}
