//a为输入, b为输出, l为元素个数, k为元素最大值 
void datalist<int>::count_sort2 ((int a[], int b[],int l,int k) {
    int* c = new int[k];
    memset(c, 0, k * sizeof(int));
    for (int j = 0; j < l; j++) c[a[j]]++;
    for (int j = 1; j < k; j++) c[j] += c[j - 1];
    for (int j = l - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]]--;
    }
    delete []c;
}
