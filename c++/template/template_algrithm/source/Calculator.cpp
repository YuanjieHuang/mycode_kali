enum Boolean {False, True};
#include "stack.h"             

class Calculator {
private:
	Stack<double> S;	//操作数栈
	void Enter(double num);
	Boolean GetTwoOperands(double& opnd1, double& opnd2);
	void Compute(char op);
public:
	Calculator(void);
	void Run(void);
	void Clear(void);
};

//操作数入栈
void Calculator::Enter(double num)
{
    S.Push(num);
}

//从栈中返回两个操作数或者给出出错信息
Boolean Calculator::GetTwoOperands(double& opnd1, double& opnd2)
{
    if (S.StackEmpty()){        //检查是否有操作数
		cerr << "Missing operand!" << endl;
		return False;
    }
    opnd1 = S.Pop();            //取右操作数
    if (S.StackEmpty()){
		cerr << "Missing operand!" << endl;
		return False;
    }
    opnd2 = S.Pop();            //取左操作数
    return True;
}

//计算两操作数, 结果入栈
void Calculator::Compute(char op)
{
    Boolean result;
    double operand1, operand2;
    result = GetTwoOperands(operand1, operand2);    //取操作数
    //取成功则计算, 并且结果入栈, 否则, 清空栈, 给出错误信息
    if (result == True)
	switch(op) {
	    case '+':   S.Push(operand2+operand1);
			break;
	    case '-':   S.Push(operand2-operand1);
			break;
	    case '*':   S.Push(operand2*operand1);
			break;
	    case '/':   if (operand1 == 0.0){
                            cerr << "Divide by 0!" << endl;
                            S.ClearStack();
                        }
		            else
			             S.Push(operand2/operand1);
			break;

	}
    else
		S.ClearStack();         //出错, 清空栈
}

//读入后缀表达式并且计算
void Calculator::Run(void)
{
    char c;
    double newoperand;
            
    while (cin >> c, c != '#') {   //结束标志“#”
        switch(c) {
            case '+':           //检查运算符
            case '-':
            case '*':
            case '/':
                Compute(c);     //有运算符, 就计算
                break;

            default:            
                //操作数入栈
                cin.putback(c);
                cin >> newoperand;
                Enter(newoperand);
                break;
        }
    }
    if (!S.StackEmpty())
        cout << S.TopandPop() << endl;  //栈顶值就是计算结果
}

