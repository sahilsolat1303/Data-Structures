/////////////////////////////////////////////////////////////////////
//
//  Function Name : CountDigits
//  Description :   Return Count of Digits of the node.
//  Input :         -
//  Output :        -
//  Auther :        Sahil Subhash Solat
//  Date :          03/01/2026
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

void CountDigits(PNODE first)
{
    int iDigit = 0, iCount = 0, num = 0;
    PNODE temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        iCount = 0;
        num = temp->data;
        while(num != 0)
        {
            iDigit = num % 10;
            num = num / 10;
            iCount++;
        }
        printf("count of Digits: %d\n",iCount);
        temp = temp->next;
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

    CountDigits(head);
    
      
    
    return 0;
}