/////////////////////////////////////////////////////////////////////
//
//  Function Name : Difference
//  Description :   difference between the max and min nodes.
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

int Difference(PNODE first)
{
    int iMax = 0, iMin = 0;
    
    iMin = first->data;

    while (first != NULL)
    {
        if(iMax < first->data)
        {
            iMax = first->data;
        }
        else if (iMin > first->data)
        {
            iMin = first->data;
        }
        first = first->next;
        
    }
    return iMax - iMin;
    
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

    iRet = Difference(head);
    printf("Difference between max and min is: %d\n",iRet);

    return 0;
}