#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int i, n, c = 0;
    // prompt the user to enter the string
    printf("Enter  the string : ");
    gets(input);
    n = strlen(input);
    // check if the string is a palindrome or not
    for (i = 0; i < n / 2; i++)
    {
        if (input[i] == input[n - i - 1])
            c++;
    }
    // print the result
    if (c == i)
        printf("Palindrome");
    else
        printf("Not Palindrome");
    return 0;
}