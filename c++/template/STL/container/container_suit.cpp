#include <iostream>
#include <stack>
#include <list>
using namespace std;
int test()
{
    //构建 stack 容器适配器
    list<int> values{ 1, 2, 3 };
    stack<int, list<int>> my_stack(values);
    //查看 my_stack 存储元素的个数
    cout << "size of my_stack: " << my_stack.size() << endl;
    //将 my_stack 中存储的元素依次弹栈，直到其为空
    while (!my_stack.empty())
    {  
        cout << my_stack.top() << endl;
        //将栈顶元素弹栈
        my_stack.pop();
    }
    return 0;
}

    #include <iostream>
#include <cmath>       // pow()
#include <stack>       // stack<T>
#include <algorithm>   // remove()
#include <stdexcept>   // runtime_error
#include <string>      // string
using std::string;
// 返回运算符的优先级，值越大，优先级越高
inline size_t precedence(const char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    throw std::runtime_error{ string {"表达中包含无效的运算符"} +op };
}
// 计算
double execute(std::stack<char>& ops, std::stack<double>& operands)
{
    double result{};
    double rhs{ operands.top() }; // 得到右操作数
    operands.pop();                                   
    double lhs{ operands.top() }; // 得到做操作数
    operands.pop();                                    
    switch (ops.top()) // 根据两个操作数之间的运算符，执行相应计算
    {
    case '+':
        result = lhs + rhs;
        break;
    case '-':
        result = lhs - rhs;
        break;
    case '*':
        result = lhs * rhs;
        break;
    case '/':
        result = lhs / rhs;
        break;
    case '^':
        result = std::pow(lhs, rhs);
        break;
    default:
        throw std::runtime_error{ string{"invalid operator: "} +ops.top() };
    }
    ops.pop(); //计算完成后，该运算符要弹栈
    operands.push(result);//将新计算出来的结果入栈
    return result;
}
int main()
{
    std::stack<double> operands; //存储表达式中的运算符
    std::stack<char> operators; //存储表达式中的数值
    string exp;  //接受用户输入的表达式文本
    try
    {
        while (true)
        {
            std::cout << "输入表达式(按Enter结束):" << std::endl;
            std::getline(std::cin, exp, '\n');
            if (exp.empty()) break;
            //移除用户输入表达式中包含的无用的空格
            exp.erase(std::remove(std::begin(exp), std::end(exp), ' '), std::end(exp));
            size_t index{};
            //每个表达式必须以数字开头,index表示该数字的位数
            operands.push(std::stod(exp, &index)); // 将表达式中第一个数字进栈
            std::cout << index << std::endl;
            while (true)
            {
                operators.push(exp[index++]); // 将运算符进栈
                size_t i{};
                operands.push(std::stod(exp.substr(index), &i));  //将运算符后的数字也进栈,并将数字的位数赋值给 i。
                index += i;  //更新 index
                if (index == exp.length())                  
                {
                    while (!operators.empty())  //如果 operators不为空，表示还没有计算完
                        execute(operators, operands);
                    break;
                }
                //如果表达式还未遍历完，但子表达式中的运算符优先级比其后面的运算符优先级大，就先计算当前的子表达式的值
                while (!operators.empty() && precedence(exp[index]) <= precedence(operators.top()))
                    execute(operators, operands);
            }
            std::cout << "result = " << operands.top() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "计算结束" << std::endl;
    return 0;
}