/////////////////////////////////////////////////////////////////////
//
//  Function Name : CountDivByFive
//  Description :   Count of nodes that are divisible by five.
//  Input :         -
//  Output :        -
//  Auther :        Sahil Subhash Solat
//  Date :          04/01/2026
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

void CountDivByFive(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        if((first->data % 5) == 0)
        {
            iCount++;
        }
        first = first->next;
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
    InsertFirst(&head,-41);
    InsertFirst(&head,11);
    InsertFirst(&head,-11);
    InsertFirst(&head,123456781);
    InsertFirst(&head,41);

    Display(head);

    iRet = CountDivByFive(head);
    printf("Count of nodes that are divisible by five: %d\n",iRet);


    return 0;
}