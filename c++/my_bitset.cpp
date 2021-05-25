#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <algorithm>
#include <iterator>
#include <bitset>
using namespace std;

#define PI 3.14159265
#define e 2.71828182

int mem_func(){
	//bitset 使用整数初始化bitset
	bitset<3> bs(7);
	//输出bs各个位的值
	cout<<"bs[0] is "<<bs[0]<<endl;
	cout<<"bs[1] is "<<bs[1]<<endl;
	cout<<"bs[2] is "<<bs[2]<<endl;
	//下面的语句会抛出outofindexexception
	//cout<<"bs[3] is "<<bs[3]<<endl;
 
	//使用字符串初始化bitset
	//注意：使用string初始化时从右向左处理，如下初始化的各个位的值将是110，而非011
	string strVal("011");
	bitset<3> bs1(strVal);
	//输出各位	
	cout<<"bs1[0] is "<<bs1[0]<<endl;
	cout<<"bs1[1] is "<<bs1[1]<<endl;
	cout<<"bs1[2] is "<<bs1[2]<<endl;
	//cout输出时也是从右边向左边输出
	cout<<bs1<<endl;
 
	//bitset的方法
	//any()方法如果有一位为1，则返回1
	cout<<"bs1.any() = "<<bs1.any()<<endl;
 
	//none()方法，如果有一个为1none则返回0，如果全为0则返回1
	bitset<3> bsNone;
	cout<<"bsNone.none() = " <<bsNone.none()<<endl;
 
	//count()返回几个位为1
	cout<<"bs1.count() = "<<bs1.count()<<endl;
 
	//size()返回位数
	cout<<"bs1.size() = "<<bs1.size()<<endl;
 
	//test()返回某一位是否为1
	//flip()诸位取反
	bitset<3> bsFlip = bs1.flip();
	cout<<"bsFlip = "<<bsFlip<<endl;
 
	//to_ulong
	unsigned long val = bs1.to_ulong();
	cout<<val;
        bitset<32> bitvec2(0xffff); // bits 0 ... 15 are set to 1; 16 ... 31 are 0
    cout << "bitvec2: " << bitvec2 << endl;
	return 0;
}

int bitset_test() {
    int n;
    while (cin >> n) {
        bitset<15> ans(n);
        bool flag = false;
        for (int i = 14; i >= 0; --i) {
            if (ans[i]) flag = true;
            if (flag) cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}

/*
[hiho一下 第147周](https://hihocoder.com/contest/hiho147/problem/1)，这个题较难，如果想到用bitset就会很简单。
**描述**
小Hi从小的一大兴趣爱好就是学习，但是他发现尽管他认真学习，依旧有学神考的比他好。
小Hi在高中期间参加了市里的期末考试，一共五门：语文、数学、英语、物理、化学。
成绩出来之后，小Hi发现有些同学，所有科目都考的比他好，他很烦恼。所以他想知道所有科目都比自己名次靠前的同学的人数。
为了方便，可以认为不存在两个人某一门名次是相同的。
其他同学们也想知道有多少人全面碾压了他们，所以你需要对所有人输出答案。

**输入**
第一行，一个正整数N(N <= 30000)，表示人数。
接下来N行，每行五个整数，分别表示五门课依次的排名。
输出
输出共N行，每行一个整数，表示答案。

**样例输入**
> 4
1 1 2 2 1
2 3 3 3 2
3 2 1 1 3
4 4 4 4 4

**样例输出**
> 0
1
0
3

思路：首先设法将每门科目的排名列出，开一个二维的bitset数组，根据每门科目的排名利用&运算，求出所有科目都比当前人名次靠前的同学的人数。
*/



typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 30000 + 5;
const int INF = 0x3f3f3f3f;
bitset<MAX_N> ls[5][MAX_N];//ls[j][i]表示第j个科目排名为1到i的是哪些人
int arr[5][MAX_N];//arr[j][i]表示第j个科目排名为i的是谁
bitset<MAX_N> ans;
int _rank[5][MAX_N];//_rank[j][i]表示第j个科目第i位同学的排名

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            int val;
            scanf("%d", &val);
            arr[j][val] = i;
            _rank[j][i] = val;
        }
    }
    for (int j = 0; j < 5; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (i == 1) ls[j][i] = 0;
            else {
                ls[j][i] = ls[j][i - 1];
                ls[j][i].set(arr[j][i - 1]);//名次从前往后走，依次将上一个人设为1
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = ls[0][_rank[0][i]];
        for (int j = 1; j < 5; ++j) {
            ans &= ls[j][_rank[j][i]];
        }
        cout << ans.count() << endl;
    }
    return 0;
}
