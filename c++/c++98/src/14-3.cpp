//标准输入示例
#include <iostream>
using namespace std;

int main()
{   int grade, highestGrade = -1;
    cout << "Enter grade (enter end-of-file to end): ";
    while ( cin >> grade) {
        if ( grade > highestGrade) highestGrade = grade;
        cout << "Enter grade (enter end-of-file to end): ";
    }
    cout << "\n\nHighest grade is: "<< highestGrade << endl;
    return 0;
}