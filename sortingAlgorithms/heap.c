#include <stdio.h>
#define N 100
#define M 7

void heapify(int* heap, int len, int i);
void heapSort(int* heap, int len);
void swap(int* x, int* y);
void printHeap(int* arr, int len);
int insert(int* heap, int len, int data);
void swim(int* heap, int i);

int main(void)
{
    int heap[N];
    //-1 represents void
    for(int i = 0; i < N; i++)
    {
        heap[i] = -1;
    } 

    int arr[M] = {30, 16, 50, 15, 10, 20, 8};

    //initiation
    for(int i = 0; i < M; i++)
    {
        heap[i] = arr[i];
    }


    printHeap(heap, M);
    for(int i = (M / 2 - 1); i >= 0; i--)
    {
        heapify(heap, M, i);
    }
    printHeap(heap, M);
    int len = insert(heap, 7, 60);
    printHeap(heap, len);

    
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printHeap(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// void sink()
// {

// }
void swim(int* heap, int i)
{
    if(i > 0)
    {
        int tmp = heap[i];
        int p_x; //parent index
        if(i % 2 == 1) p_x = i/2;
        else if(i % 2 == 0) p_x = i / 2 - 1;

        if(tmp > heap[p_x])
        {
            swap(&heap[i], &heap[p_x]);
            swim(heap, p_x);
        }
    }
}

int insert(int* heap, int len, int data)
{
    int index = len;
    heap[index] = data;
    len++;

    swim(heap, index);

    
    return len;
}

void heapify(int* heap, int len, int i)
{
    int max = i;
    int lc = 2*i + 1;
    int rc = 2*i + 2;

    if(lc < len &&heap[lc] >heap[max])
    {
        max = lc;
    }
    if(rc < len &&heap[rc] >heap[max])
    {
        max = rc;
    }

    if(max != i)
    {
        swap(&heap[max], &heap[i]);
        heapify(heap, len, max);
    }
}
void heapSort(int* heap, int len)
{

    for(int i = (len / 2 - 1); i >= 0; i--)
    {
        heapify(heap, len, i);
    }

    for(int i = len - 1; i >= 0; i--)
    {
        swap(&heap[0], &heap[i]);
        heapify(heap, i, 0);
    }
}
