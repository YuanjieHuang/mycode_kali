void Hanoi(int n, string startpeg, string middlepeg, string endpeg)
{ 
    if(n == 1) //终止条件：移动一个盘子
        cout << "move" << startpeg << "to" << endpeg << endl;
    else {
        Hanoi(n-1, startpeg, endpeg, middlepeg); //将n-1个盘子移到middlepeg栓, 将底盘移//到endpeg栓
        cout << "move" << startpeg << "to" << endpeg << endl;
        Hanoi(n-1, middlepeg, startpeg, endpeg); //然后再将n-1个盘子从middlepeg栓移至
                                                 //endpeg栓
    }    
}
