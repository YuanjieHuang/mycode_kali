void bmPreprocess2()
{
    int i, j;
    j=f[1];
    for (i=1; i<=m; i++){
        if (s[i]==0) s[i]=j;
        if (i==j) j=f[j];
    }
}
