void place(int k)
{
    int i = 1;
    while (i < MAXQUEEN)
    {
        if (!attack(k, i))  {
            queen[k] = j;
            if (k == MAXQUEEN - 1)  {
                for (j = 1; j < MAXQUEEN; j++)
                    cout << j << queen[j];
                cout << endl;
            }
            else
                place(k+1);
        }
        i++;
    }
}

int attack(int k, int i)
{
    int j, m, atk;
    atk = 0;
    j = 1;
    while ((atk == 0) && (j < k))  {
        m = queen[j];
        atk = (m == i) || (abs(m-i) == abs(j-k));
        j++;
    }
    return(atk);
}
