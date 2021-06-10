//用t返回串s中第个i字符开始的长度为len的子串1<=i<=串长
int StrSub (String &t, String s, int i, int len)
{
    int slen;
    slen = s.strLength();
    if (i<1 || i>slen || len<0 || len>slen-i+1)  { cerr << ＂参数不对＂ << endl;
        return 0;
    }
    for(j=0; j<len; j++)
        t.buffer[j] = s.buffer[i+j-1];
    t.buffer[j] = '\0'; 
    return 1;
}
