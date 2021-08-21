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
