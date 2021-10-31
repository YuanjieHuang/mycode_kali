#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char str[128];
    printf("请输入字符串：");
    scanf("%s",str);
    printf("转换为整数后为%d。\n",atoi(str));
    printf("转换为整数后为%d。\n",atol(str));
    printf("转换为整数后为%d。\n",atof(str));
    return 0;
 }
a) =,assign()     //赋以新值
b) swap()     //交换两个字符串的内容
c) +=,append(),push_back() //在尾部添加字符
d) insert() //插入字符
e) erase() //删除字符
f) clear() //删除全部字符
g) replace() //替换字符
h) + //串联字符串
i) ==,!=,<,<=,>,>=,compare()    //比较字符串
j) size(),length()    //返回字符数量
k) max_size() //返回字符的可能最大个数
l) empty()    //判断字符串是否为空
m) capacity() //返回重新分配之前的字符容量
n) reserve() //保留一定量内存以容纳一定数量的字符
o) [ ], at() //存取单一字符
p) >>,getline() //从stream读取某值
q) <<    //将谋值写入stream
r) copy() //将某值赋值为一个C_string
s) c_str() //将内容以C_string返回
t) data() //将内容以字符数组形式返回
u) substr() //返回某个子字符串
v)查找函数
w)begin() end() //提供类似STL的迭代器支持
x) rbegin() rend() //逆向迭代器
y) get_allocator() //返回配置器
1 str.find_last_of("apple");
2 //返回 apple 中任何一个字符最后一次在 str 中出现的位置
3 str.find_last_of("apple", 2);
4 //返回 apple 中任何一个字符最后一次在 str[0]~str[2] 范围中出现的位置
5 str.find_last_not_of("apple");
6 //返回除 apple 以外的任何一个字符在 str 中最后一次出现的位置
7 str.find_last_not_of("apple", 2);
8 //返回除 apple 以外的任何一个字符在 str[0]~str[2] 范围中最后一次出现的位置
1 str.substr(3); 
2 //返回 [3] 及以后的子串
3 str.substr(2, 4); 
4 //返回 str[2]~str[2+(4-1)] 子串(即从[2]开始4个字符组成的字符串)
1 str.push_back('a');
2 //在 str 末尾添加字符'a'
3 str.append("abc");
4 //在 str 末尾添加字符串"abc"
1 str.erase(3);
2 //删除 [3] 及以后的字符，并返回新字符串
3 str.erase(3, 5);
4 //删除从 [3] 开始的 5 个字符，并返回新字符串
1 str1.swap(str2);
2 //把 str1 与 str2 交换
 1 str.size();
 2 //返回字符串长度
 3 str.length();
 4 //返回字符串长度
 5 str.empty();
 6 //检查 str 是否为空，为空返回 1，否则返回 0
 7 str[n];
 8 //存取 str 第 n + 1 个字符
 9 str.at(n);
10 //存取 str 第 n + 1 个字符（如果溢出会抛出异常）