/*
vector的存储区是连续的，所以我们可以通过第一个元素的地址获取vector数据的指针。
vector＜int＞intContainer;
…
int*pData=NULL;
pData=＆(intContainer[0]);
pData2=＆(intContainer.begin()[0]);
//或者pData=＆(*intContainer.begin());
pData=＆(intContainer.front());
//或者pData=＆((＆intContainer.front())[0]);
如果获取的是第n个元素，只需要将上面的0换作n即可：
//方式1
pData=＆(intContainer[n]);
//方式2
pData=＆(intContainer.begin()[n]);
//方式3
pData=＆((＆intContainer.front())[n]);
对于string，不要采用类似vector的方法，因为并不是所有的string实现采用的都是连续内存。幸好string提供了一个成员函数c_str，它返回一个以“\0”结束的C风格的字符串：
string str="hello 2011";
const char *sz=str.c_str();
*/