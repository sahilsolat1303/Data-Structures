/////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayPerfect
//  Description :   Return element which are perfect in singly linear 
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

void DisplayPerfect(PNODE first)
{
        
        while (first != NULL)
        {
            int iSum = 0;
            int i = 0;
            for(i = 1; i<=(first->data/2);i++)
            {
                if(first->data % i == 0)
                {
                    iSum = iSum+i;
                }
            }

            if(iSum == first->data)
            {
                printf("%d",first->data)
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
    int iRet = 0;

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    InsertFirst(&head,101);
    InsertFirst(&head,6);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    
    printf("Perfect Number are: ");
    DisplayPerfect(head);       

    return 0;
}