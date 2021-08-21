template <class Record,class Compare>
void Bubble_Sort2(Record a[], int n)
{
    int low = 0,high = n-1;
    int change = 1;
    int i, temp;
    while (low < high&&change) {
        change = 0;
        for (i = low; i < high; i++)
            if Compare::gt(a[i], a[i+1])) {
                
                swap(a[i], a[i+1]);		//a[i]与a[i+1]交换
                change=1;
            }
        high--;
        for (i = high; i > low; i--)
            if Compare::lt(a[i], a[i-1])) {
                
                swap(a[i],a[i-1]);		//a[i]与a[i-1]交换
                change=1;
            }
        low++;
    }
}
