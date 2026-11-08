#include <stdio.h>
#include <stdlib.h>

int main()
{int  sum=0,x[100],count=0;
    for(int i=0;i<100;i++)
    {
        count++;
        scanf("%d",&x[i]);
        if(x[i]==0)break;
    }
    for(int i=0;i<count;i++)
    {
        if(x[i]%2==1)
        {
            sum+=x[i];
        }
    }
    printf("%d\n",sum);
    return 0;
}
