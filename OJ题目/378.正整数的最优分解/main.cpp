#include <stdio.h>
#include <math.h>

int main()
{
    long long n;
    scanf("%lld",&n);
    if(n%2==1) printf("-1");
    else
    {
        for(int  i=30;i>0;i--)
        {
           if(n>=pow(2,i))
           {
               printf("%lld ",(long long)pow(2,i));
               n-=pow(2,i);
           }
           if(n==0) break;
        }

    }
    return 0;
}
