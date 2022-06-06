#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct linkedList {
    node* head;
    node* tail;
} linkedList;


node* newNode(int val)
{
    node* temp = malloc(sizeof(node*));
    temp->value = val;
    temp->next = NULL;

    return temp; 
}

linkedList* pushAtTail(linkedList* myList, int val) 
{
    node* temp = newNode(val);

    if(myList->tail == NULL){
        myList->tail = temp;
    }
    temp->next = myList->head;
    myList->head = temp;
    return myList;


}

linkedList* pop(linkedList* myList)
{
    if(myList->tail == NULL)
    {
        return myList;
    }

    node* ix = myList->head;

    while(ix->next != myList->tail)
    {
        ix = ix->next;
    }
    //(myList->tail)->next = ix;

    myList->tail = ix;
    ix->next = NULL;
    return myList;
}

void printList(linkedList* myList)
{
    node* temp = myList->head;

    while(temp !=NULL)
    {
        printf("\n\t%p -- %d\n", temp, temp->value);
        temp = temp->next;
    }
}

//recursive printArr
void recPrintList(node* node)
{

    if(node->next == NULL)
    {
        printf("%d ", node->value);
        return;
    }
    printf("%d ", node->value);
    recPrintList(node->next);
}
int main()
{
    linkedList* myList = malloc(sizeof(linkedList*));

    myList = pushAtTail(myList, 16);
    myList = pushAtTail(myList, 8);
    myList = pushAtTail(myList, 4);
    
    recPrintList(myList->head);

    myList = pop(myList);
    printf("\n");

    recPrintList(myList->head);
    
    return 0;
}