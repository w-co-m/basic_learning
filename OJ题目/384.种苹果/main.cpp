#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x[30],sum=0;
    scanf("%d",&n);
    for(int  i=0;i<n+1;i++)
    {
        scanf("%d",&x[i]);
        sum+=x[i];
    }
    int  max=x[1],max_count=1;
    for(int j=1;j<n+1;j++)
    {
        if(x[j]<max)
        {
            max=x[j];
            max_count=j;
        }
    }
    printf("%d %d\n",sum,max_count);
    return 0;
}
