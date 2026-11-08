#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char s[51], res[101]; 
    int i = 0, j = 0;
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') s[len - 1] = '\0';
    while (s[i] != '\0')
    {
        char ch = s[i]; 
        i++;
        int cnt = 0;    

        while (s[i] != '\0' && isdigit(s[i]))
        {
            cnt = cnt * 10 + (s[i] - '0'); 
            i++;
        }
        if (cnt == 0) cnt = 1;
        for (int k = 0; k < cnt; k++)
        {
            res[j++] = ch;
        }
    }
    res[j] = '\0'; 
    printf("%s\n", res);
    return 0;
}