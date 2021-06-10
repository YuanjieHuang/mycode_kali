int StrIndex_BF　(String s, String t) //从串s的第一个字符开始找首次与串t相等的子串
{
    int i = 1,j = 1;
    while (I <= s.buffer[0] && j <= t.buffer [0])	//都没遇到结束符
        if (s.buffer[i] == t.buffer[j])
        { i++; j++; }								//继续
        else 
        { i = i-j+2; j = 1; }						//回溯
    if (j > t.buffer [0])  return (i - t.buffer[0]);	//匹配成功, 返回存储位置
    else  return –1;
}
