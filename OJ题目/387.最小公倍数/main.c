#include <stdio.h>


int main()
{
    int a,b,c,temp=1,x;
    scanf("%d %d",&a,&b);
    if(a>b)
    {
        x=a; a=b; b=x;
    }
    for(int i=2;i<=b/2+1;i++)
    {
        if(a%i==0&&b%i==0)
        {
            temp*=i;
        }
    }
    c=a*b/temp;
    printf("%d\n",c);
    return 0;
}
