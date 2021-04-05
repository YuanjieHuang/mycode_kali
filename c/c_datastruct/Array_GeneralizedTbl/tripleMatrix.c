    #include<stdio.h>
    #define number 3
    //三元组结构体
    typedef struct {
        int i,j;//行标i，列标j
        int data;//元素值
    }triple;
//矩阵的结构表示
typedef struct {
    triple data[number];//存储该矩阵中所有非0元素的三元组
    int n,m,num;//n和m分别记录矩阵的行数和列数，num记录矩阵中所有的非0元素的个数
}TSMatrix;
    //输出存储的稀疏矩阵
    void display(TSMatrix M);
    int main() {
        TSMatrix M;
        M.m=3;
        M.n=3;
        M.num=3;
        M.data[0].i=1;
        M.data[0].j=1;
        M.data[0].data=1;
        M.data[1].i=2;
        M.data[1].j=3;
        M.data[1].data=5;
        M.data[2].i=3;
        M.data[2].j=1;
        M.data[2].data=3;
        display(M);
        return 0;
    }
    void display(TSMatrix M){
        for(int i=1;i<=M.n;i++){
            for(int j=1;j<=M.m;j++){
                int value =0;
                for(int k=0;k<M.num;k++){
                    if(i == M.data[k].i && j == M.data[k].j){
                        printf("%d ",M.data[k].data);
                        value =1;
                        break;
                    }
                }
                if(value == 0)
                    printf("0 ");
            }
            printf("\n");
        }
    }