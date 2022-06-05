#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);

    }
    printf("\n");
}


void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int* arr, int first , int last)
{

    int pivot = first;
    int i = first + 1;
    int j = last;

    int arrP = arr[pivot];

    while(i < j)
    {
        for(; arr[j] > arrP; j--);
        for(; arr[i] <= arrP && i < last; i++);

        
        if(i < j)
        {
            swap(&arr[i], &arr[j]);

        }
    }

    swap(&arr[j], &arr[pivot]);
    return j;

}

void quicksort(int* arr, int first, int last)
{
    printf("--->  ");
    printArr(arr, 10);

    if(first < last)
    {
        int m = partition(arr, first, last);
        quicksort(arr, first, m - 1);
        quicksort(arr, m + 1, last);
        
    }
}
void shuffle(int* arr, int len)
{
    srand(time(NULL));

    for(int i = 0; i < len; i++)
    {
        int random = rand() % len;    
        swap(&arr[i], &arr[random]);
    }
}
int main(void)
{

    int arr[10] = {-4, 4, 1, 0, 6, 32, 12, -5, 9, 11};
    printArr(arr, 10);
    //shuffle(arr, 10);
   // printArr(arr, 10);
    quicksort(arr, 0, 9);
    printArr(arr, 10);
}
