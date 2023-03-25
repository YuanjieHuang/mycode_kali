#include "sort.h"

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
            j -= 1;
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
#if 0
// 将 arr 从 start 到 end 分区，左边区域比基数小，右边区域比基数大，然后返回中间值的下标
static int partition(int[] arr, int start, int end) {
    // 取第一个数为基数
    int pivot = arr[start];
    // 从第二个数开始分区
    int left = start + 1;
    // 右边界
    int right = end;
    while (left < right) {
        // 找到第一个大于基数的位置
        while (left < right && arr[left] <= pivot) left++;
        // 找到第一个小于基数的位置
        while (left < right && arr[right] >= pivot) right--;
        // 交换这两个数，使得左边分区都小于或等于基数，右边分区大于或等于基数
        if (left < right) {
            exchange(arr, left, right);
            left++;
            right--;
        }
    }
    // 如果 left 和 right 相等，单独比较 arr[right] 和 pivot
    if (left == right && arr[right] > pivot) right--;
    // 将基数和轴交换
    exchange(arr, start, right);
    return right;
}
#endif
int min(int a, int b)
{
    if(a>=b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
void merge_sort(int arr[], int len) {
    int* a = arr;
    int* b = (int*) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}

void merge_sort_recursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}


// void quick_sort(int arr[], const int len) {
//     if (len <= 0)
//         return; // 避免len等於負值時引發段錯誤（Segment Fault）
//     // r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素
//     Range r[len];
//     int p = 0;
//     r[p++] = new_Range(0, len - 1);
//     while (p) {
//         Range range = r[--p];
//         if (range.start >= range.end)
//             continue;
//         int mid = arr[(range.start + range.end) / 2]; // 選取中間點為基準點
//         int left = range.start, right = range.end;
//         do
//         {
//             while (arr[left] < mid) ++left;   // 檢測基準點左側是否符合要求
//             while (arr[right] > mid) --right; //檢測基準點右側是否符合要求
 
//             if (left <= right)
//             {
//                 swap(&arr[left],&arr[right]);
//                 left++;right--;               // 移動指針以繼續
//             }
//         } while (left <= right);
 
//         if (range.start < right) r[p++] = new_Range(range.start, right);
//         if (range.end > left) r[p++] = new_Range(left, range.end);
//     }
// }


void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
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
        if(key[mid] == k)
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
    // test_sort(diminishingIncrementSort);
    // test_quickSort();
    return 0;
}