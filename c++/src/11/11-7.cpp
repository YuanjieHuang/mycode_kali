　　Counter & Counter::operator++()
　　{   if (value == alarm) cout << "已超过报警值\n";
　　        else { ++value;
　　                if (value == alarm) cout << "已到达报警值\n";
　　        }
　　    return *this;
　　}
　　
　　Counter Counter::operator++(int x)
　　{   Counter tmp = *this; 			//保存对象修改前的状态
　　    if (value == alarm) cout << "已超过报警值\n";
　　        else { ++value;
　　                if (value == alarm) cout << "已到达报警值\n";
　　        }
　　    return tmp;				 //返回修改前的状态
　　}
　　
