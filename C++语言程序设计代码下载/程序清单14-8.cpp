程序清单14-8
// ***************************************************************
// palindrome.cpp
// 功能： 判断给定文本是否回文（正读反读都一样的文本）
//        演示stack适配器的使用
// ***************************************************************
#include <iostream>
#include <stack>
#include <string>
#include <cctype>	// 使用其中的tolower()

using namespace std;

bool palindrome(const string& text);

int main()
{
	string text;

	while (true) {
		// 输入文本
		cout << "Enter the text(\"quit\" to end program):" << endl;
		getline(cin, text);

		if (text == "quit")
			break;

		if (palindrome(text)) 	// 是回文
			cout << "The text you typed is a palindrome." << endl;
		else					// 不是回文
			cout << "The text you typed is NOT a palindrome." << endl;
	}
	
	return 0;
}

bool palindrome(const string& text)
// 功能：判断文本text是否为回文
// 后置条件：若text为回文，则返回值为true；否则返回值为false
{
	stack<char> cstack;
	size_t length = text.size();

	// 将文本text的前半部分压入栈cstack
	for (size_t i = 0; i < length/2; i++) 
		cstack.push(text[i]);

	// 将文本text的后半部分逐个字符与前半部分的对应字符进行比较
	size_t comparePos;	// 比较位置
	// 设定比较起点
	if (length % 2 == 0)
		comparePos = length / 2;
	else
		comparePos = length / 2 + 1;

	// 比较对应字符
	while (!cstack.empty()) {
		if (text[comparePos] != cstack.top())	// 对应字符不相同
			break;
		cstack.pop();							// 对应字符出栈
		comparePos++;							// 比较位置后移一个字符
	}

	if (cstack.empty())						// 所有对应字符都相同
		return true;
	else
		return false;
}
