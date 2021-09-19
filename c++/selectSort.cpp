#include <iostream>
#include "test.h"

using namespace std;

//选择排序
template<typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n; i++) {

        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(arr[i], arr[minIndex]);
    }
}

int main() {

    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    delete[] arr;

    system("pause");

    return 0;
}