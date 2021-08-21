// ***************************************************************
// scoresAnalysis.cpp
// 功能： 对用户从键盘输入的一系列考试分数进行排序，按升序输出排序
//        之后的所有分数，对优秀（90～100），中等（70～79），
//        不及格（59以下）分数段中的分数进行计数并输出计数结果
// ***************************************************************
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class BetweenCls {
public:
	BetweenCls(int ival1, int ival2): lowerBound(ival1), upperBound(ival2)
	{ }
	bool operator() (const int& ival)
	{
		return (ival > lowerBound && ival < upperBound);
	}
private:
	int lowerBound, upperBound;
};
int main()
{
	vector<int> scores;
	int score;
	// 输入要处理的分数，并存储在vector容器中
	cout << "Enter scores you want to analy(Ctrl-Z to end):" << endl;
	while (cin >> score) {
		// 检查分数的合法性
		if (score < 0 || score >100) {
			continue;	// 舍弃无效分数
		}
		scores.push_back(score);
	}
	// 对容器中的元素序列进行排序
	sort(scores.begin(), scores.end());
	// 输出升序排列的分数序列
	cout << "Sorted scores:" << endl;
	for (vector<int>::iterator iter = scores.begin(); 
		iter != scores.end(); iter++) {
		cout << *iter << '\t';
	}
	cout << endl << "Number of affect scores: " << scores.size() << endl;
	// 输出各分数段中分数的计数结果
	cout << "Number of excellence:" << '\t' << count_if(scores.begin(), scores.end(), 
		 BetweenCls(89, 101)) << endl;
	cout << "Number of middle:" << '\t'
		 << count_if(scores.begin(), scores.end(), BetweenCls(69, 80)) << endl;
	cout << "Number of fail:" << '\t'
		 << count_if(scores.begin(), scores.end(), BetweenCls(-1, 60)) << endl;
	return 0;
}
