/*
静态查找表以及动态查找表中的一些查找方法，其查找的过程都无法避免同查找表中的数据进行比较，查找算法的效率很大程度取决于同表中数据的查找次数。
哈希表可以通过关键字直接找到数据的存储位置，不需要进行任何的比较.

数据的哈希地址=f（关键字的值）
哈希地址只是表示在查找表中的存储位置，而不是实际的物理存储位置。
在构建哈希表时，最重要的是哈希函数的设计。
常用的哈希函数的构造方法有 6 种：直接定址法、数字分析法、平方取中法、折叠法、除留余数法和随机数法。

直接定址法：其哈希函数为一次函数，即以下两种形式：
H（key）= key 或者 H（key）=a * key + b
其中 H（key）表示关键字为 key 对应的哈希地址，a 和 b 都为常数。


数字分析法:如果关键字由多位字符或者数字组成，就可以考虑抽取其中的 2 位或者多位作为该关键字对应的哈希地址，在取法上尽量选择变化较多的位，避免冲突发生。

平方取中法是对关键字做平方操作，取中间得几位作为哈希地址。此方法也是比较常用的构造哈希函数的方法。

折叠法是将关键字分割成位数相同的几部分（最后一部分的位数可以不同），然后取这几部分的叠加和（舍去进位）作为哈希地址。此方法适合关键字位数较多的情况。

除留余数法：若已知整个哈希表的最大长度 m，可以取一个不大于 m 的数 p，然后对该关键字 key 做取余运算，即：H（key）= key % p。

随机数法：是取关键字的一个随机函数值作为它的哈希地址，即：H（key）=random（key），此方法适用于关键字长度不等的情况。

处理冲突的方法:
开放定址法 H（key）=（H（key）+ d）MOD m（其中 m 为哈希表的表长，d 为一个增量） 当得出的哈希地址产生冲突时，选取以下 3 种方法中的一种获取 d 的值，然后继续计算，直到计算出的哈希地址不在冲突为止，这 3 种方法为：
    线性探测法：d=1，2，3，…，m-1
    二次探测法：d=12，-12，22，-22，32，…
    伪随机数探测法：d=伪随机数
再哈希法
当通过哈希函数求得的哈希地址同其他关键字产生冲突时，使用另一个哈希函数计算，直到冲突不再发生。
链地址法
将所有产生冲突的关键字所对应的数据全部存储在同一个线性链表中。
*/
    #include <stdio.h>
    #include <stdlib.h>
    #define HASHSIZE 7 //定义散列表长为数组的长度
    #define NULLKEY -1
    typedef struct{
        int *elem;//数据元素存储地址，动态分配数组
        int count; //当前数据元素个数
    }HashTable;
    //对哈希表进行初始化
    void Init(HashTable *hashTable){
        int i;
        hashTable->elem= (int *)malloc(HASHSIZE*sizeof(int));
        hashTable->count=HASHSIZE;
        for (i=0;i<HASHSIZE;i++){
            hashTable->elem[i]=NULLKEY;
        }
    }
    //哈希函数(除留余数法)
    int Hash(int data){
        return data%HASHSIZE;
    }
    //哈希表的插入函数，可用于构造哈希表
    void Insert(HashTable *hashTable,int data){
        int hashAddress=Hash(data); //求哈希地址
        //发生冲突
        while(hashTable->elem[hashAddress]!=NULLKEY){
            //利用开放定址法解决冲突
            hashAddress=(++hashAddress)%HASHSIZE;
        }
        hashTable->elem[hashAddress]=data;
    }
    //哈希表的查找算法
    int Search(HashTable *hashTable,int data){
        int hashAddress=Hash(data); //求哈希地址
        while(hashTable->elem[hashAddress]!=data){//发生冲突
            //利用开放定址法解决冲突
            hashAddress=(++hashAddress)%HASHSIZE;
            //如果查找到的地址中数据为NULL，或者经过一圈的遍历回到原位置，则查找失败
            if (hashTable->elem[hashAddress]==NULLKEY||hashAddress==Hash(data)){
                return -1;
            }
        }
        return hashAddress;
    }
    int main(){
        int i,result;
        HashTable hashTable;
        int arr[HASHSIZE]={13,29,27,28,26,30,38};
        //初始化哈希表
        Init(&hashTable);
        //利用插入函数构造哈希表
        for (i=0;i<HASHSIZE;i++){
            Insert(&hashTable,arr[i]);
        }
        //调用查找算法
        result= Search(&hashTable,29);
        if (result==-1) printf("查找失败");
        else printf("29在哈希表中的位置是:%d",result+1);
        return  0;
    }