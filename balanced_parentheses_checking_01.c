/*
Problem: Balanced Parentheses Checking Using Stack 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

struct listNode
{
    char item;
    struct listNode *next;
};
struct listNode *list;
int top = -1;

void push(char item)
{
    struct listNode * newNode;
    newNode = (struct listNode*) malloc (sizeof(struct listNode));

    newNode->item = item;
    newNode->next = list;
    list = newNode;
    top++;
}

int pop()
{
    struct listNode *temp;
    char pop_item;
     
    pop_item = list->item;
    temp = list->next;
    free(list);

    list = temp;
    top--;
    return pop_item;
}

int isEmpty()
{
    if (top == -1)
        return TRUE;
    else
        return FALSE;
}

int main()
{
    char inputStr[100];
    int length;

    printf("Enter your string of parentheses: ");
    gets(inputStr);
    length = strlen(inputStr);

    for (int i=0; i<length; i++)
    {
        if (inputStr[i]=='(' || inputStr[i]=='{' || inputStr[i]=='[')
        {
            push(inputStr[i]);
            continue;
        }
        if (inputStr[i]==')' || inputStr[i]=='}' || inputStr[i]==']')
        {
            if (inputStr[i]==')')
            {   
                if (list->item=='(')
                    pop();
                else
                {
                    printf("\nUnbalanced Expression.\n\n");
                    break;
                }
            }
            if (inputStr[i]=='}')
            {   
                if (list->item=='{')
                    pop();
                else
                {
                    printf("\nUnbalanced Expression.\n\n");
                    break;
                }
            }
            if (inputStr[i]==']')
            {   
                if (list->item=='[')
                    pop();
                else
                {
                    printf("\nUnbalanced Expression.\n\n");
                    break;
                }
            }
            
        }
    }
    if (top == -1)
        printf("\nBalanced Expression.\n\n");
}