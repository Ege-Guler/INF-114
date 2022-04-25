/*
    mergeSort.c
    time complexity: O(nlogn)
    Ege Guler - Galatasaray University
    04/22/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void merge(int* arr, int h, int m, int l)
{
    int lenFirst = m - l + 1;
    int lenSecond = h - m;
    
    int tmp1[lenFirst];
    int tmp2[lenSecond];

    for(int i = 0; i < lenFirst; i++)
    {
        tmp1[i] = arr[i + l];
    }
    for(int i = 0; i < lenSecond; i++)
    {
        tmp2[i] = arr[m +1 + i];
    }

    int x = 0, y = 0, z = l;

    while(x < lenFirst && y < lenSecond)
    {
        if(tmp1[x] < tmp2[y])
        {
            arr[z] = tmp1[x];
            x++;
        }
        else
        {
            arr[z] = tmp2[y];
            y++;
        }
        z++;
    }

    while(x < lenFirst)
    {
        arr[z] = tmp1[x];
        x++;
        z++;
    }
    
    while(y < lenSecond)
    {
        arr[z] = tmp2[y];
        y++;
        z++;
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

void mergeSort(int* arr, int h, int l)
{
    if(h > l)
    {
        int m = (h + l) / 2;
        mergeSort(arr, m, l);
        mergeSort(arr, h, m + 1);
        merge(arr, h, m, l);
    }
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
    mergeSort(arr, 9, 0);
    printf("\n----------------Sorted Array----------------\n");
    printArr(arr);


    return 0;
}
