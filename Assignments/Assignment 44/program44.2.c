/////////////////////////////////////////////////////////////////////
//
//  Function Name : CountEven
//  Description :   Count even numbers from the LinkedList.
//  Input :         -
//  Output :        -
//  Auther :        Sahil Subhash Solat
//  Date :          1/01/2026
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

int CountEven(PNODE first)
{
    int iCount = 0;
    PNODE temp = first;
    while (temp != NULL)
    {
        if(temp->data % 2 == 0)
        {
            iCount++;
        }
        temp = temp->next;
    }
    return iCount;
    
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
    int iRet = 0;

    InsertFirst(&head,11);
    InsertFirst(&head,20);
    InsertFirst(&head,32);
    InsertFirst(&head,41);

    Display(head);

    iRet = CountEven(head);
    printf("Count of Even number is :%d",iRet);
        
    return 0;
}