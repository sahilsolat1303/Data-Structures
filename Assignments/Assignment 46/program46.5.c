/////////////////////////////////////////////////////////////////////
//
//  Function Name : IncrementAll
//  Description :   Increment LinkedList elements by 1.
//  Input :         -
//  Output :        -
//  Auther :        Sahil Subhash Solat
//  Date :          2/01/2026
//
/////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

#pragma pack(1)
struct node
{
    int data;
    struct node *next; 
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }

}

void IncrementALL(PPNODE first)
{
    PNODE temp = *first;
    while (temp != NULL)
    {
        temp->data = temp->data + 1; 
        printf(" | %d | ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
     
}

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | ->",first->data);
        first = first->next;
    }
    printf("NULL\n");
    
}

int main()
{
    PNODE head = NULL;
  

    InsertFirst(&head,11);
    InsertFirst(&head,20);
    InsertFirst(&head,32);
    InsertFirst(&head,-41);
    InsertFirst(&head,11);
    InsertFirst(&head,-11);
    InsertFirst(&head,11);
    InsertFirst(&head,41);

    Display(head);

    IncrementALL(&head);
      
    
    return 0;
}