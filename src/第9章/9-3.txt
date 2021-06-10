void play()
{   int coin ;
    char flag = 'Y';

    srand(time(NULL)); //设置随机数种子
    while (flag == 'Y' || flag =='y')
        { coin = rand() * 2 / (RAND_MAX + 1);  //生成扔硬币的结果
        if (get_call_from_user() == coin) cout << "你赢了";
        else  cout << "我赢了";
        cout << "\n继续玩吗（Y或y）？";
        cin >> flag;
    }
}

