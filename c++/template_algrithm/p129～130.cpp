//s: 读入字符串
//Words：分词结果表 
//countTable：基本词汇表, 采用散列表存储
ParseChinese(string s, List  &Words, HashTable countTable)
{
    int length = s.Length(); 
    String temp; temp.MakeEmpty();
    for (int i=0; i<s.Length;)  {
        temp = s.Substring(i, 1);
        if (countTable.GetCount(temp)>1)  { //不只一个子串
            int j = 2;
            for (; i+j < s.Length+1 && countTable.GetCount(s.Substring(i, j)) > 0; j++)
            {}
            temp = s.Substring(i, j-1);
            i = i + j - 2;
        }
        i++;
        words.Insert(temp);	//一个分词
    }
}
