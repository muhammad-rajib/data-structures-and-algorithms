// Stack implementation using Single Linked List 

#include<stdio.h>
#include<stdlib.h>

#define STACK_MAX_SIZE 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0
int top;

struct listNode
{
    int item;
    struct listNode *next;
};
struct listNode * list;
int top;

void initializeList()
{
    list = 0;
    top=0;
}

int push(int item)
{
    if(top == STACK_MAX_SIZE) return NULL_VALUE ;
    
    struct listNode * newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    
    newNode->item = item ;
    newNode->next = list ;
    list = newNode ;
    top++;
    
    return SUCCESS_VALUE ;
}

int pop()
{
    if(top == 0) return NULL_VALUE ;
    
    struct listNode *temp;
    int pop_item;

    temp = list->next;
    pop_item = list->item;
    free(list);
    list = temp;
    top--;
    return pop_item;
}

int IsEmpty()
{
    if(top == 0) return TRUE_VALUE ;
    else return FALSE_VALUE ;
}

int IsFull()
{
    if(top == STACK_MAX_SIZE) return TRUE_VALUE ;
    else return FALSE_VALUE ;
}

void PrintAll()
{
    struct listNode *temp;
    temp = list ;
    while (temp != 0)
    {
        printf("%d ",temp->item);
        temp = temp->next ;
    }
    printf("\n");
}

int main()
{
    int a,result;
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        switch(ch)
        {
        case 'P':
            scanf("%d",&a);
            result=push(a);
            break;
        case 'p':
            result=pop();
            printf("%d\n",result);
            break;
        case 's':
            PrintAll();
            break;
        default:
            break;
        }
        if(result==NULL_VALUE) break;
    }
}