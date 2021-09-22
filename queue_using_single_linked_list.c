#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX_SIZE 4
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0

struct listNode
{
    int item ;
    struct listNode *next ;
} ;
struct listNode *list, *rear;
int length;

void initializeQueue()
{
    list = 0 ;
    rear = 0;
    length = 0 ;
}

int enqueue(int item)
{
    if (length == QUEUE_MAX_SIZE) 
    {
        printf("Overflow...");
        return NULL_VALUE;
    }

    struct listNode *newNode, *temp;
    newNode = (struct listNode*)malloc(sizeof(struct listNode));

    newNode->item = item;
    newNode->next = NULL;

    if(length == 0)
    {
        list = newNode ;
        length++;
        rear = newNode;
        return SUCCESS_VALUE ;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        length++;
        return SUCCESS_VALUE;
    }
}

int dequeue()
{
    if(length == 0) 
    {   
        printf("Underflow...\n");
        return NULL_VALUE ;
    }
    struct listNode *temp;
    int pop_item;

    temp = list->next;
    pop_item = list->item;
    free(list);
    list = temp;
    length--;
    return pop_item;
}

int full()
{
    if(length == QUEUE_MAX_SIZE) 
        return TRUE_VALUE ;
    else 
        return FALSE_VALUE ;
}
 
int empty()
{
    if(length == 0) 
        return TRUE_VALUE ;
    else 
        return FALSE_VALUE ;
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
        case 'E':
            scanf("%d",&a);
            result=enqueue(a);
            break;
        case 'D':
            result=dequeue();
            printf("%d\n",result);
            break;
        case 'P':
            PrintAll();
            break;
        case 'f':
            result=full();
            printf("%d\n",result);
            break;
        case 'e':
            result=empty();
            printf("%d\n",result);
            break;
        default:
            break;
        }
        if(result==NULL_VALUE) break;
    }
}
