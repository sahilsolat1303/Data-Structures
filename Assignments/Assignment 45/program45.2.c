/////////////////////////////////////////////////////////////////////
//
//  Function Name : FirstOcc
//  Description :   return first occurence of the number.
//  Input :         -
//  Output :        -
//  Auther :        Sahil Subhash Solat
//  Date :          1/01/2025
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

int FirstOcc(PNODE first, int no)
{
    int pos = 1;
    PNODE temp = first;
    while (temp != NULL)
    {
        if(temp->data == no)
        {
            return pos;
        }
        pos++;
        temp = temp->next;
    }
   return pos;
    
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
    int iValue = 0;
    int iRet = 0;

    InsertFirst(&head,11);
    InsertFirst(&head,20);
    InsertFirst(&head,32);
    InsertFirst(&head,41);
    InsertFirst(&head,11);
    InsertFirst(&head,11);
    InsertFirst(&head,11);
    InsertFirst(&head,41);

    Display(head);
    
    printf("Enter the element:\n");
    scanf("%d",&iValue);

    iRet = FirstOcc(head,iValue);
    printf("Position of first Occurrence is :%d",iRet);

    return 0;
}