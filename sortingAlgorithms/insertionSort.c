/*
    insertionSort.c
    time complexity: 
        best-case: O(n)
        worst-case: O(n^2)
    Ege Guler - Galatasaray University
    04/17/2022
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

}

void insertionSort(int* arr, int ix)
{
    int j, tmp;

    for(int i = 1; i < N; i++)
    {
        j = i;

        while(arr[j] < arr[j -1])
        {
            swap(&arr[j - 1], &arr[j]);
            j--;
        }

    }


}

void printArr(int* arr)
{
    for(int i = 0; i < N - 1; i++)
    {
        printf("%d - ", arr[i]);
    }
    printf("%d", arr[N - 1]);
}

int main(void)
{
    int arr[N];
    srand(time(NULL)); 
    for(int i = 0; i < N; i++)
    {
        arr[i] = rand() % 21;
    }
    printf("\n----------------Unsorted Array----------------\n");
    printArr(arr);
    insertionSort(arr, 1);
    printf("\n----------------Sorted Array----------------\n");
    printArr(arr);
 
    return 0;
}
