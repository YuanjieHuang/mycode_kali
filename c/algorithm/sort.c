#include <stdio.h>



typedef int keytype;
// void insertsort(keytype k[], int n)
// {
//     int i,j;
//     keytype tmp;
//     for(i=2; i <= n; i++)
//     {
//         tmp = k[i];
//         j = i -1;
//         while (j > 0 && tmp < k[j])
//         {
//             k[j+1] = k[j--];         //a=++i 相当于 i++ , a=i
                                        //a=i++ 相当于 a=i , i++
//         }
//         k[j+1] = tmp;
//     }
// }

void insertSort(int a[], int n)
{
    int i,j;
    for(i = 2; i <= n; i++)
    {
        a[0] = a[i];
        j = i -1;
        while (j > 0 && a[0] > a[j])//找a[i]插入位置，即j的值
        {
            a[j+1] = a[j];
            j-=1;
        }
        a[j+1] = a[0];
    }
}

void selectSort(int a[], int n)
{
    int i,j,max;
    for(i = 1;i <= n-1; i++)
    {
        max = i;
        for(j = i+1; j <= n; j++)
        {
            if(a[j] > a[max])
            {
                max = j;
            }
        }
        if(max != i)
        {
            a[0]   = a[max];
            a[max] = a[i];
            a[i]   = a[0];
        }
    }
}
#if 1
void bubbleSort(int a[], int n)//先排尾部
{
    int i,j,flag = 1;
    for(i=1; i<= n-1 && flag == 1; i++)
    {
        flag = 0;
        for(j=1; j <= n-i; j++)
        {
            if(a[j] < a[j+1])
            {
                a[0]    = a[j+1];
                a[j+1]  = a[j];
                a[j]    = a[0];
                flag    = 1;
            }

        }
    }
}
#else
void bubbleSort(int a[], int n)
{
    int i,j;
    for(i=1; i<= n-1; i++)
    {
        for(j=1; j <= n-i; j++)
        {
            if(a[j] > a[j+1])
            {
                a[0] = a[j+1];
                a[j+1] = a[j];
                a[j] = a[0];
                
            }

        }
    }
}
#endif

void diminishingIncrementSort(int a[], int n)//shell's sort
{
    int i, j, flag, gap = n;
    while(gap > 1)
    {
        gap = gap / 2;
        do
        {
            flag = 0;
            for(i = 1; i <= n - gap; i++)
            {
                j = i + gap;
                if(a[i] < a[j])
                {
                    a[0]  = a[i];
                    a[i] = a[j];
                    a[j] = a[0];
                    flag = 1;
                }
            }

        }while (flag != 0);
    }
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a  = *b;
    *b  = tmp;
}

void quickSort(int a[], int s, int t)
{
    int i,j;
    if(s < t)
    {
        i = s;
        j = t + 1;
        while (1)
        {
            do
            {
                i++;
            }while(!(a[s] >= a[i] || i == t));
            do
            {
                j--;
            }while(!(a[s] <= a[j] || j == s));
            if(i < j)
            {
                swap(&a[i], &a[j]);
            }
            else
            {
                break;
            }
        }
        swap(&a[s], &a[j]);     //交换基准元素与a[j]的位置
        quickSort(a, s, j-1);   //递归基准元素前面的子序列
        quickSort(a, j+1, t);   //..........后面.......
    }
}

typedef void (*test)(int*,int);// = NULL;

void test_sort(test sortTest)
{
    int i = 0;
    int a[8] = {-11, 1, 5, 8, 2, 4, 7, 3};
    for(i=1;i<=7;i++)
    {
        printf("a[%d]:%-3d\t",i,a[i]);
    }
    printf("\n");
    sortTest(a,7);
    for(i=1;i<=7;i++)
    {
        printf("a[%d]:%-3d\t",i,a[i]);
    }
    printf("\n");
    printf("\n");
}

void test_quickSort()
{
    int i = 0;
    int a[8] = {-11, 1, 5, 8, 2, 4, 7, 3};
    for(i=0;i<=7;i++)
    {
        printf("a[%d]:%-3d\t",i,a[i]);
    }
    printf("\n");
    quickSort(a,0,7);
    for(i=0;i<=7;i++)
    {
        printf("a[%d]:%-3d\t",i,a[i]);
    }
    printf("\n");
    printf("\n");
}

//折半查找
int binSearch(keytype key[], int n, keytype k)
{
    int low= 0, high = n-1, mid;
    while (low < high)
    {
        mid = (low + high)/2;
        if(key[mid] = key)
        {
            return mid;     //查找成功
        }
        if(k > key[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    test_sort(insertSort);
    test_sort(selectSort);
    test_sort(bubbleSort);
    test_sort(diminishingIncrementSort);
    test_quickSort();
}