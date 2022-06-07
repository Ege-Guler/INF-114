#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void swap(int* x, int* y)
{
    int temp = *x;

    *x = *y;
    *y = temp;

}


int partition(int* arr, int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high;


    while(i < j)
    {
        while(arr[i++] <= arr[pivot] && i < high);

        while(arr[j--] > arr[pivot]);
        
        if(i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[j], &arr[pivot]);
    return j;
}

void quickSort(int*arr, int low, int high)
{

    if(high > low)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void printArr(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void shuffle(int* arr, int len)
{
    srand(time(NULL));

    for(int i = 0; i < len; i++)
    {
        int r = rand() % len;
        swap(&arr[i], &arr[r]);
    }
}


int main(void)
{
    int random;
    srand(time(NULL));

    int SIZE = rand() % 50 + 1;

    int* array = malloc(sizeof(int) * SIZE);
 
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = (rand() % 201) -100;
    }

    printArr(array, SIZE);
    shuffle(array, SIZE);
    quickSort(array,0 ,SIZE -1);
    printArr(array, SIZE);

    return 0;
}
