#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    fgets(a, sizeof(a),stdin);
    int count = 0, num[100], temp=0,flag=0;
    for (int i = 0; i < strlen(a); i++)
    {
        if ('0' <= a[i] && '9' >= a[i])
        {
            flag = 1;
            temp = temp * 10 + int(a[i] - '0');
        }
        else
        {
            if (flag == 1)
            {
                num[count] = temp;
                count++;
                temp = 0;
                flag = 0;
            }
        }
    }
    if (temp != 0)
    {
        num[count] = temp;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if (num[i] < num[j])
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d ", num[i]);
    }
        return 0;
}