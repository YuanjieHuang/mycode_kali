int get_call_from_user()
{   int  guess;   // 0 = head, 1 = tail
    do { cout << "\n输入你的选择（0表示正面，1表示反面）:";
        cin >> guess;
    } while (guess != 0 && guess != 1);
    return guess;
}

