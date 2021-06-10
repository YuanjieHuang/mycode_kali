void bmInitocc()
{
    char a;
    int j;
    for (a = 0; a < alphabetsize; a++) occ[a] = -1;
    for (j=0; j<m; j++)  {
        a = p[j];
        occ[a] = j;
    }
}
