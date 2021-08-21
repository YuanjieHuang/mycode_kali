void proc_1(Stack S)   {  
    int i, n, A[255];
    n＝0;
    while (! EmptyStack(S))  {
        n++; Pop(&S, &A[n]);
     }
     for (i = 1; i <= n; i++)
         Push(&S, A[i]);
}
