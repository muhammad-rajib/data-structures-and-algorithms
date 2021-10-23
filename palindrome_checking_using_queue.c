#include<stdio.h>
#include<string.h>

#define SIZE 100
char items[SIZE], front = -1, rear = -1;

void Enqueue(char item)
{
    if (front == -1)
        front=0;
    rear++;
    items[rear] = item;
}

char Dequeue()
{
    char pop_item;
    pop_item = items[front];
    front++;
    if (front > rear)
        front = rear = -1;
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
        Enqueue(word[i]);

    int isPalindrom = 1;

    //Palindrom checking
    int count = length-1;
    for (int i=0; i<length; i++)
    {
        char ch = Dequeue();
        if (ch != word[count])
            isPalindrom = 0;
        count--;
    }

    if (isPalindrom == 1)
        printf("Yes, It's a Palindrom word.");
    else
        printf("It's not a Palindrom word.");

    return 0;
}