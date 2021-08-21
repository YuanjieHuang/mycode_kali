void hanoi2(int n, char x, y, z)
{ 
    struct levelstr  { 
        int ptrn;
        char xp, yp, zp; 
    } s[arrmax]; 
    int top; char temp; top = 0; 
    s[top] = (n, x, y, z); //栈初始化 
    while (!((top == 0) && (s[top].ptrn == 1)))  { 
        while (s[top].ptrn > 1)
            s[top++] = (s[top].ptrn-1, s[top].xp, s[top].zp, s[top].yp); 
        move(s[top].xp, 1, s[top].zp);
        if (top > 0) { 
            top--; 
            move(s[top].xp, s[top].ptrn, s[top].zp); 
            s[top].ptrn--; 
            temp = s[top].xp; 
            s[top].xp = s[top].Yp; 
            s[top].yp = temp; 
        } 
    } 
    move(s[top].xp, 1, s[top].zp);
    top--;
}
