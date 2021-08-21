void proc_3(Queue *Q)   {  
    Stack S; int d;
    InitStack(&S);
    while (!EmptyQueue(*Q))  {
        DeleteQueue(Q, &d);
        Push(&S, d);
    }
    while(!EmptyStack(S))    {  
        Pop(&S, &d);
        EnterQueue(Q, d);
    }
}
