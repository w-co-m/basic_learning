#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[6];

    int count=0;

        scanf("%c %c %c %c %c",&x[0],&x[1],&x[2],&x[3],&x[4]);

    for(int i=0;i<6;i++)
    {
        if(x[i]=='A'||x[i]=='a') count++;
    }
    printf("%d",count);
    return 0;
}
