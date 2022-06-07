/*
    mergeSort.c
    time complexity: O(nlogn)
    Ege Guler - Galatasaray University
    04/22/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* A, int* C, int low, int mid, int high)
{
    for(int k = low; k <= high; k++)
    {
        C[k] = A[k];
    }

    int i = low;
    int j = mid + 1;

    for(int k = low; k <= high; k++)
    {
        if(i > mid)
        {
            A[k] = C[j++];
        }
        else if(j > high)
        {
            A[k] = C[i++];
        }
        else if(C[i] > C[j])
        {
            A[k] = C[j++];
        }
        else
        {
            A[k] = C[i++];
        }
    }
    

}

void sort(int* A, int* C, int low, int high)
{

    if(high > low)
    {
        int mid = low + (high - low) / 2;
        sort(A, C, low, mid);
        sort(A, C, mid + 1, high);
        merge(A, C, low, mid, high);
    }
}


void mergeSort(int* A, int len)
{  
    int C[len];

    sort(A, C, 0, len - 1);
}

void printArr(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int random;
    srand(time(NULL));

    int SIZE = rand() % 50;

    int* array = malloc(sizeof(int) * SIZE);
 
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = (rand() % 201) -100;
    }

    printArr(array, SIZE);
    mergeSort(array, SIZE);
    printArr(array, SIZE);


    return 0;
}
