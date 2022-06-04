/*
    mergeSort.c
    time complexity: O(nlogn)
    Ege Guler - Galatasaray University
    04/22/2022
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void merge(int* arr, int l, int m, int h);
void sort(int* arr, int h, int l);
void printArr(int* arr, int len);



int main(void)
{
    srand(time(NULL));

    int SIZE = rand() % 18 + 2;
    printf("%d", SIZE);

    int *arr = (int* )malloc(SIZE* sizeof(int));

    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 41 - 20;
    }

    

    printf("\n---Unsorted Arr---\n");
    printArr(arr, SIZE);
    sort(arr, SIZE -1, 0);
    printf("\n----Sorted Arr----\n");
    printArr(arr, SIZE);

    free(arr);
    return 0;
}

void merge(int* arr, int l, int m, int h)
{

    int lenFirst = m - l + 1;
    int lenSecond = h - m;

    int tempFirst[lenFirst];
    int tempSecond[lenSecond];

    for(int i = 0; i < lenFirst; i++)
    {
        tempFirst[i] = arr[i + l];
    }

    for(int i = 0; i < lenSecond; i++)
    {
        tempSecond[i] = arr[i + m + 1];
    }

    int i = 0, j = 0, k = l;

    while(i < lenFirst && j < lenSecond)
    {
        if(tempFirst[i] < tempSecond[j])
        {
            arr[k] = tempFirst[i];
            i++; 
        }
        else
        {
            arr[k] = tempSecond[j];
            j++;
        }
        k++;
    }

    for(; i < lenFirst; arr[k] = tempFirst[i], i++, k++);
    for(; i < lenSecond; arr[k] = tempSecond[i], j++, k++);

}

void sort(int* arr, int h, int l)
{
    if(h > l)
    {
        int m = (h + l) / 2;
        sort(arr, m , l);
        sort(arr, h, m + 1);
        merge(arr, l, m, h);
    }
}

void printArr(int* arr, int len)
{

    for(int i = 0; i < len - 1; i++)
    {
        printf("%d | ", arr[i]);
    }
    printf("%d", arr[len - 1]);
}
