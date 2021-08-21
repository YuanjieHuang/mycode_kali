void Hanoi(int n, char x, y, z)
{ 
    if (n == 1) move(x, 1, z); //将编号为1的盘子从x移到z  
    else { 
        Hanoi(n-1, x, z, y); 
        Move(x, n, z);
        Hanoi(n-1, y, x, z);
    } 
}
