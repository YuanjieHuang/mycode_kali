void bmSearch()
{
    int i=1, j;
    while (i <= n-m+1){
        j = m-1;
        while (j >= 1 && p[j] == t[i+j]) j--;
        if (j < 1)  {
            report(i);
            i+=s[1];
        }
        else i+=max(s[j+1], j-occ[t[i+j]]);
    }
}
