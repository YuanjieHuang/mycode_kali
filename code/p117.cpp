//从串s的第pos个字符开始找首次与串t相等的子串
int StrIndex_KMP(char *s,char *t,int pos)
{  
    int i=pos, j=1, slen, tlen;
    while (i <= s[0] && j <= t[0])		//都没遇到结束符
        if (j == 0|| s[i] == t[j]) { i++; j++; }
        else  j = next(j);		//回溯
    if (j > t[0])  return  i - t[0];	//匹配成功, 返回存储位置
    else  return  –1;
}
