#include <stdio.h>
#include <math.h>
// #include <algorithm>
#include <stdlib.h>
typedef int keytype;
typedef void (*test)(int*,int);// = NULL;
void insertSort(int a[], int n);
void selectSort(int a[], int n);
void bubbleSort(int a[], int n);//先排尾部
void diminishingIncrementSort(int a[], int n);//shell's sort
void swap(int *a, int *b);
void quickSort(int a[], int s, int t);
void merge_sort(int arr[], int len);
void merge_sort_recursive(int arr[], int reg[], int start, int end) ;
void quick_sort(int arr[], const int len);
void quick_sort_recursive(int arr[], int start, int end);
void test_sort(test sortTest);
void test_quickSort();
//折半查找
int binSearch(keytype key[], int n, keytype k);