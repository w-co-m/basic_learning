#include<stdio.h>

int main()
{
    char   letter, upper, front, rear;
    scanf_s("%c", &letter);
    upper = letter - 32;
    if (upper > 'A' && upper < 'Z')
    {
        front = upper - 1;
        rear = upper + 1;
    }
    else if (upper == 'A')
    {
        front = 'Z';
        rear = 'B';
    }
    else if (upper == 'Z')
    {
        front = 'Y';
        rear = 'A';
    }
    printf("%c\t%c\t%c\n", upper, front, rear);
    return 0;
}