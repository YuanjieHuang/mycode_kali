typedef char * *HuffmanCode; 		//动态分配数组存储赫夫曼编码表

//对赫夫曼树HT, 求出n个字符的赫夫曼编码HC
void HuffmanCoding(HTNode &HT, HuffmanCode &HC, int n)
{
    int c,f,i,start;
    char *cd;
    //从叶子到根逆向求每个字符的赫夫曼编码
    HC = new (char**)[n+1];	//分配n个字符编码的头指针向量
    cd = new (char *)[n];   	//分配求编码的工作空间
    cd[n-1] = '\0';        	//编码结束符位置
    for (i = 1; i <= n; i++) {   	//逐个字符求赫夫曼编码    
        start=n-1;
        for (c = i,f = HT[i].parent; f != 0; c = f, f = HT[f].parent)//从叶子到根逆向求
//编码写入操cd
            if(HT[f].left == c) cd[--start] = '0';
            else cd[--start] = '1';
        HC[i] = new(char*)[n-start];	//为第i个字符编码分配空间
        strcpy(HC[i], &cd[start]);	//从cd复制编码(串)到HC[i]
    }
    delete cd; //释放工作空间
}  
