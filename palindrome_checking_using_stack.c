#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Stack implementation using single linked list
#define STACK_MAX_SIZE 100
#define SUCCESS_VALUE 99999

struct listNode
{
    char item;
    struct listNode *next;
};
struct listNode *list;

void initializeList()
{
    list = 0;
}

int push(char item)
{
    struct listNode * newNode;
    newNode = (struct listNode*) malloc (sizeof(struct listNode));

    newNode->item = item;
    newNode->next = list;
    list = newNode;

    return SUCCESS_VALUE;
}

int pop()
{
    struct listNode *temp;
    char pop_item;

    temp = list->next;
    pop_item = list->item;
    free(list);

    list = temp;
    return pop_item;
}

int main()
{
    char word[100];
    printf("Enter your word: ");
    scanf("%s", word);

    int length = strlen(word);
    
    //input word in stack
    for(int i=0; i<length; i++)
        push(word[i]);

    int isPalindrom = 1;

    //Palindrom checking
    for (int i=0; i<length; i++)
    {
        char ch = pop();
        if (ch != word[i])
            isPalindrom = 0;
    }

    if (isPalindrom == 1)
        printf("Yes, It's a Palindrom word.");
    else
        printf("It's not a Palindrom word.");

    return 0;
}
