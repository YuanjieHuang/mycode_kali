void proc_2(Stack S, int e)  {
    Stack T; int d;
    InitStack(&T);
    while (!EmptyStack(S))   {  
        Pop(&S, &d);
        if (d != e) Push(&T, d);
    }
    while(!EmptyStack(T))    {  
        Pop(&T, &d);
        Push(&S, d);
    }
}
