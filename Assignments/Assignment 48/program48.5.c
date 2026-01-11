/////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayOddPosition
//  Description :   Display odd position nodes.
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

void DisplayOddPosition(PNODE first)
{
    int iPos = 0; 

    printf("Elements at Odd position:\n");
    while(first != NULL)
    {
        
        iPos++;
        if(iPos % 2 != 0)
        {
            printf("| %d | -> ",first->data);
        }
        else
        {
            printf("|   | -> ",first->data);
        }
        first = first->next;
    } 
    
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
    InsertFirst(&head,123456781);
    InsertFirst(&head,41);

    Display(head);

    DisplayOddPosition(head);

    return 0;
}