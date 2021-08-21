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
