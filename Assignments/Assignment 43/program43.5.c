/////////////////////////////////////////////////////////////////////
//
//  Function Name : SumDigit
//  Description :   Return Addition of digit of element in singly linear 
//                  linked list.
//  Input :         int
//  Output :        int
//  Auther :        Sahil Subhash Solat
//  Date :          31/12/2025
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

int SumDigit(PNODE first)
{
      
      PNODE temp = first;
      while (temp!= NULL)
      {
        int sum = 0;
        int iDigit = temp->data;
        while(iDigit!= 0)
        {
            sum += iDigit % 10;
            iDigit = iDigit / 10;
            
        }
        printf("%d\t",sum);
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
    InsertFirst(&head,41);
       

    Display(head);
    
    SumDigit(head);
    
    return 0;
}