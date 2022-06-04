#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define N 6
int swap(int* x, int* y);
int partition(int* arr, int low, int high);
void quickSort(int* arr, int low, int high);
void printArr(int* arr);
void shuffleArr(int* arr, int len);


int main(void)
{



    int arr[N] = {3, 9, 2, 4, 1, 7};
    printf("\n**Unsorted Array**\n");
    printArr(arr);
    shuffleArr(arr, N);
    printf("\n**Shuffled Array**\n");
    printArr(arr);
    quickSort(arr, 0, 5);
    printf("\n**Sorted Array**\n");
    printArr(arr);

    return 0;
}



int partition(int* arr, int low, int high)
{
    int i = low + 1;
    int j = high;

    int pivot = low;

    while(i < j)
    {
        for(; arr[j] > arr[pivot]; j--);
        for(; arr[i] < arr[pivot];  i++);

        if(i < j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }

    }

    swap(&arr[j], &arr[pivot]);

    return j;
}

void quickSort(int* arr, int low, int high)
{
    if(low < high)
    {
        int j = partition(arr, low, high);
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high );
    }
}

int swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArr(int* arr)
{
    //int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < N - 1; i++)
    {
        printf("%d - ", arr[i]);
    }
    printf("%d", arr[N - 1]);
}

void shuffleArr(int* arr, int len)
{
    srand(time(NULL));
    int random;

    for(int i = len - 1; i > 0; i--)
    {
        random = rand() % i;
        swap(&arr[random], &arr[i]);

    }
}
