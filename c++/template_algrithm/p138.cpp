//m, n是矩阵A的行和列
void  saddle (int A[][],int m, int n)
{ 
    int i, j, min;
    for (i = 0; i < m; i++)  {			//按行处理
        min = A[i][0]; 
        for (j = 1; j < n; j++)
            if (A[i][j] < min ) min = A[i][j];	//找第i行最小值
                for (j = 0; j < n; j++)			//检测该行中的每一个最小值是否是鞍点
                    if (A[i][j] == min)  {
                        k=j;  p=0;
                        while (p < m && A[p][j] < min) p++;
                        if (p >= m) printf(＂%d,%d,%d\n＂, i, k, min);
                    }
    } 
}
