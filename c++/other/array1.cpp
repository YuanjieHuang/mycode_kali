// #include "pch.h"
#include <iostream>
using namespace std;
int main(void)
{
	char key[] = { 'a','c','b','a','d' };
	char c;
	int ques = 0, numques = 5, numcorrect = 0;
	cout << "Enter the " << numques << " question tests:" << endl;
	while (cin.get(c))		//cin.get():cinG逰剺稼棶旓繟服
	{
		if (c != '\n')
			if (c == key[ques])
			{
				numcorrect++;
				cout << " ";
			}
			else	cout << "*";
		else
		{
			cout << " Score " << float(numcorrect) / numques * 100 << "%";
			ques = 0;	   // reset variables￺冘飙縋一乍伍
			numcorrect = 0;
			cout << endl;
			continue;
		}
		ques++;
	}
	return 0;
}
