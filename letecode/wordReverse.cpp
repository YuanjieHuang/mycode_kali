#include <iostream>
#include <vector>
#include <string>

using namespace std;

#if 0
void singleReverse(string &src)
{
    unsigned i = 0, j = 0;
    vector<string> words;
    while(i < src.length())
    {
        if(src[i] == ' ' || i == src.length() -1)
        {
            words.push_back(src.substr(j, i-j+1));
            j = i;
        }
        i++;
    }
    src.clear();
    for(vector<string>::reverse_iterator riter = words.rbegin();riter != words.rend(); ++riter)
    {
        src += *(riter);
    }
    cout<<src;
}
void reverse(string &src)
{
    vector<string> words;
    unsigned i = 0, j =0, len = src.length();
    string s;

    while (i < len)
    {
        if(src[i] == ',' || i == len -1)
        {
            string recur = src.substr(j, i-j);
            singleReverse(recur);
            if(src[i] == ',')
            {
                cout<<src[i];
            }
            j = i;
        }
        // else
        // {
        //     s += src[i];
        //     if(src[i] == ' ')
        //     {
        //         words.push_back(s);
        //         s.clear();
        //     }
            
        // }
        ++i;
    }
    
}
#endif

void singleReverse(string &src)
{
    unsigned len = src.size();
    unsigned fcur = 0, fsplit = 0, lsplit = len, lcur = len;
    while (fsplit < len)
    {
        fsplit = src.find_first_of(' ', fcur);
        if(fsplit == -1)
        {
            fsplit = len;
        }
        if(fsplit != fcur)
        {
            swap(src.substr(fcur, fsplit), (src.substr(lsplit, lcur)));
            fcur = fsplit + 1;
            lcur = lsplit - 1;
        }
    }
    
    

}
void reverse(string &src)
{
    unsigned curIndex = 0, splitIndex = 0;
    while (curIndex < src.length())
    {
        splitIndex = src.find_first_of(',',curIndex);
        if(splitIndex == -1)
        {
            splitIndex = src.size();
        }
        if(splitIndex != curIndex)
        {
            string tmp = src.substr(curIndex, splitIndex);
            singleReverse(tmp);
            if(splitIndex != src.size())
                cout<<',';
        }
        curIndex = splitIndex + 1;
    }
    
    
}
int main()
{
    string str = "you and me,god bless you";
    string s = "you and me";
    // singleReverse(s);
    // cout<<s<<endl;
    reverse(str);
    // cout<<str<<endl;
    return 0;
}