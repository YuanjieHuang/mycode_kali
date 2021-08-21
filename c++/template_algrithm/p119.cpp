//求模式t的next值并存入next数组中 
void GetNext(char *t,int next[])
{  
    int i=1,j=0;
    next[1]=0;
    while (i < t[0])
    {   while (j > 0 && t[i] != t[j])  j = next[j];
        i++;  j++; 
        if (t[i] == t[j])  next[i] = next[j]; 
        else  next[i] = j;
    }
}
