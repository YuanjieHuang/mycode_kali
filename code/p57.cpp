#include "stack.h"

const int MaxLength = 100; 		//最大表达式长度

void PrintMatchedPairs(char *expr)	//括号匹配算法
{ 
    Stack<int> s(MaxLength);
    int j, length = strlen(expr);

    //扫描表达式中的(和)
    for (int i = 1; i <= length; i++) {
        if (expr[i - 1] == '(') s.Push(i);
        else if (expr[i - 1] == ')')
            try { s.TopandPop(j);  //匹配
                cout << j << ' ' << i << endl; }
            catch (OutOfBounds)
            {   cout << "No match for right parenthesis"
                     << " at " << i << endl; }
    }
    ...
    //栈非空则不匹配
    while (!s.IsEmpty()) {
        s.TopandPop(j);
        cout << "No match for left parenthesis at " << j << endl;
    }
}
