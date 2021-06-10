程序清单3-2
int x;
cin >> x;
if (x >= 90) {
    cout << " You got an excellent score!" << endl;
    if (x >= 95)
        cout << "A+";
    else
        cout << "A";
}
else if (x >= 80) {
    cout << " You got a good score!" << endl;
    if ( x>= 85)
        cout << "B+";
    else
        cout << "B";
}
else if (x >= 70) {
    cout << " You got a medium score!" << endl;
    if (x >= 75)
        cout<< "C+";
    else
        cout<< "C";
}
else if (x >= 60) {
    cout << " You got a pass exam!" << endl;
    if (x >= 65)
        cout << "D+";
    else
        cout << "D";
}
else if (x < 60) {
    cout << " You fail in the exam!" << endl;
    cout<< "E";
}
