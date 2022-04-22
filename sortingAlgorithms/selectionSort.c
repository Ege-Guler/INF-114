/*
    selectionSort.c
    time complexity: n^2

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

int findMin(int* arr, int ix)
{
    int min = ix;
    for(int i = min + 1; i < N; i++)
    {
        if(arr[i] < arr[min])
        {
            min = i;
        }
    }
    return min;

}

void selectionSort(int* arr)
{

    for(int i = 0; i < N; i++)
    {
        int min = findMin(arr, i);
        swap(&arr[min], &arr[i]);

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

int main()
{
    int arr[10];
    //to fill the array with random numbers
    srand(time(NULL)); 
    for(int i = 0; i < N; i++)
    {
        arr[i] = rand() % 21;
    }

    printArr(arr);
    selectionSort(arr);
    printf("\n----------------Sorted Array----------------\n");
    printArr(arr);

return 0;
}
