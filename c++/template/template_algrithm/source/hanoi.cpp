void Hanoi(int n, char x, y, z)
{ 
    if (n == 1) move(x, 1, z); //将编号为1的盘子从x移到z  
    else { 
        Hanoi(n-1, x, z, y); 
        Move(x, n, z);
        Hanoi(n-1, y, x, z);
    } 
}
void Hanoi(int n, char x, y, z)
{ 
    struct levelstr  { 
        int adr, ptrn;
        char xp, yp, zp;
    } *s, currentp; 
    s = new Stack(m*m-1);	//m*m-1是栈的初始化大小 
    s.push (3, n, x, y, z); 
    0:currentp = s.peek();	//局部变量currentp用来保存栈顶元素 
        if (currentp.prtn = = 1)  { 
            move(currentp.xp, 1, currentp.Zp); 
            goto currentp.adr; 
        } 
        s.push(1, currentp.ptrn-1, currentp.xp, currentp.zp, cutrretnp.Yp);
        goto 0; 
    1:s.pop(); 
        currentp = s.peek(); 
        move(currentp.Xp, currentp.Ptrn, currentp.zp);
        s.push(2, currentp.ptrn –1, currentp.yp, currentp.xp, currentp. zp);
        goto 0; 
    2:s.pop();
        currentp = s.peek();
        goto currentp.adr;
    3:s.pop();
}
void hanoi1(int n, char x, y, z)
{ 
    struct levelstr  { 
        int adr, ptrn;
        char xp, yp, zp; 
    } *s, currentp;
    s = new Stack(m*m-1); //m*m-1是栈的初始化大小 
    s.push(3, n, x, y, z);
    currentp = s.peek(); 
    do {
        while (currentp. ptrn>1) { 
            s.push(1, currentp. ptrn-1, currentp.xp, currentp. zp, cutrretnp.yp); 
            currentp = s.peek();
        } 
        move(currentp.xp, 1, currentp.zp);
        while (currentp.adr == 2)  { 
            s.pop();
            currentp = s.peek(); 
        }
        if (currentp.adr = = 1)  { 
            s.pop();
            currentp = s.peek(); 
            move(currentp.xp, currentp.ptrn, currentp.zp);
            s.push(2, currentp.ptrn-1, currentp.yp, currentp.xp, currentp.zp);
        } 
    } while (currentp.adr != 3)
    s.pop();
}
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
