/*
Program to solve josephus problem using queue data structure.
*/
#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX_SIZE 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0

/*
Queue Data Structure using Singly linked list.
*/
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
        return NULL_VALUE;

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
        return NULL_VALUE;
    
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

int main()
{
    int persons, n, skipped_number;
    printf("Enter the number of persons: ");
    scanf("%d", &persons);
    
    for (int i=1; i<=persons; i++)
    {
        enqueue(i);
    }

    // start josephus game
    n = persons;
    int first, second;

    while(n>1)
    {
        for (int j=0; j<persons; j++)
        {
            first = dequeue();
            second = dequeue();
            enqueue(first);
            n--;
        }
    }

    skipped_number = dequeue();
    printf("Output: %d\n", skipped_number);
}