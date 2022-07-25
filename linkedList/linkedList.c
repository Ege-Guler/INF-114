#include <stdio.h>
#include <stdlib.h>
//Ege Güler

typedef struct node {

    int data;
    struct node* next;
} node;

typedef struct linkedList {
    
    node* head;
    node* tail;
} linkedList;


node* newNode(int data)
{
    node* temp = malloc(sizeof(node*));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

linkedList* insertAtHead(linkedList* myList, int data)
{
    node* temp = newNode(data);
    
    if(myList->tail == NULL)
    {
        myList->tail = temp;
    }

    temp->next = myList->head;
    myList->head = temp;

}

linkedList* insertAtTail(linkedList* myList, int data)
{
    
    if(myList->tail == NULL)
    {
        insertAtHead(myList, data);
    }
    else 
    {
        node* temp = newNode(data);
        myList->tail->next = temp;
        myList->tail = temp;
    }
    


}

linkedList* deleteAtTail(linkedList* myList)
{
    if(myList->tail == NULL)
    {
        printf("List is empty\n");
        return myList;
    }
    if(myList->tail == myList->head)
    {
        myList->head = NULL;
        myList->tail = NULL;
        return myList;
        
    }

    node* pivot = myList->head;

    while(pivot->next != myList->tail)
    {
        pivot = pivot->next;
    }

    pivot->next = NULL;
    myList->tail = pivot;

    return myList;

}
linkedList* deleteAtHead(linkedList* myList)
{
    if(myList->tail == NULL)
    {
        printf("List is empty\n");
        return myList;
    }
    if(myList->tail == myList->head)
    {
        myList->head = NULL;
        myList->tail = NULL;
        return myList;
        
    }

    myList->head = myList->head->next;
    return myList;
}

void recPrint(node* headNode)
{
    if(headNode != NULL)
    {
        printf("%d ", headNode->data);
        recPrint(headNode->next);
    }
    else
    {
        printf("\n");
    }

}

int len(node* headNode)
{
    if(headNode == NULL)
    {
        return 0;
    }
    else{
        return 1 + len(headNode->next);
    }
}

int main(void)
{

    linkedList* myList = malloc(sizeof(linkedList*));

    myList = insertAtHead(myList, 15);
    myList = insertAtHead(myList, 11);
    myList = insertAtHead(myList, 13);
    myList = insertAtHead(myList, 55);
    printf("\n length of list is: %d \n", len(myList->head));
    
    recPrint(myList->head);

    //-------------

    myList = deleteAtHead(myList);
    recPrint(myList->head);
    return 0;
}
