void farmerProblem()
{
    int movers, i,location,  newlocation;
    int route[16];        //记录已考虑的状态路径
    Queue moveTo;	
    moveto.MakeEmpty();		
    moveTo.EnQueue(0x00);
    for (i = 0; i < 16; i++)    route[i] = -1;
    route[0] = 0;
    while (!moveTo.isEmpty() && (route[15] == -1)) {
        location = moveTo.GetFront(); //得到现在的状态
        moveTo.DeQueue();
        for (movers = 1; movers <= 8;movers << 1) {
            //农夫总是在移动, 随农夫移动的也只能是在农夫同侧的东西 
            if ((0! = (location & 0x08)) == (0!=(location & movers))) {
                newlocation = location^(0x08|movers);
                if (safe(newlocation) && (route[newlocation] == -1)) {
                    route[newlocation]=location;     
                    moveTo.EnQueue(newlocation);
                }
            }
         } 
    }
    if (route[15] != -1) {		//打印出路径
        cout << "The reverse path is " << endl;
        for (location = 15; location >= 0; location = route[location]) {
            cout << "The location is" << location << endl;
            if (location == 0)  exit(0); 
        }  
    }
    else  printf("No solution.\n");
}
