#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int s[SIZE];
int top = -1;
int f = 0;

int pop()
{
    return (s[top--]);
}

int push(int elem) // pushing operand in stack
{
    if (f == 1)
    {
        int num;
        num = pop();
        s[++top] = elem + 10 * num;
    }
    else if (f == 0)
    {
        s[++top] = elem;
        f = 1;
    }
}

int main() // main function
{
    int i = 0, opr1, opr2;

    while (1)
    {
        char inp;
        scanf("%c", &inp);

        if (inp != "+" && inp != "-" && inp != "*" && inp != "/")
        {
            int val = atoi(inp);
            printf("%d", val);
            push(val);
        }

        if (inp == '\0')
            break;
        else
        {
            switch (inp)
            {
            case '+':
                opr2 = pop();
                opr1 = pop();
                push(opr1 + opr2);
                break;
            case '-':
                opr2 = pop();
                opr1 = pop();
                push(opr1 - opr2);
                break;
            case '*':
                opr2 = pop();
                opr1 = pop();
                push(opr1 * opr2);
                break;
            case '/':
                opr2 = pop();
                opr1 = pop();
                push(opr1 / opr2);
                break;
            }
        }
    }
    printf("Result: %d", s[top]);
}