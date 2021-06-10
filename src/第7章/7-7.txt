//文件名：7-7.cpp
//菜单功能的实现
int main()
{   int select;

    while(1) {
        cout << "1--add \n";
        cout << "2--erase\n";
        cout << "3--modify\n";
        cout << "4--print salary\n";
        cout << "5--print report\n";
        cout << "0--quit\n";

        cin >> select;
   
        switch(select) 
        {   case 0: return 0;
            case 1: add(); break;
            case 2: erase(); break;
            case 3: modify(); break;
            case 4: printSalary(); break;
            case 5: printReport(); break;
            default: cout << "input error\n";
        }
    }
}

