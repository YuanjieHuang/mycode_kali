//文件名：7-8.cpp
//用函数指针实现菜单选择
int main()
{   int select;
    void (*func[6])() = {NULL, add, erase, modify, printSalary, printReport};

    while(1) {
    cout << "1--add \n";
    cout << "2--delete\n";
    cout << "3--modify\n";
    cout << "4--print salary\n";
    cout << "5--print report\n";
    cout << "0--quit\n";

    cin >> select;
   
    if (select == 0) return 0;
    if (select > 5) cout << "input error\n"; else func[select]();
    }
}

