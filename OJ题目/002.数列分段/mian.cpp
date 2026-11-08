#include <stdio.h>


int main()
{
   int n,a[1000],num=1;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }

       for(int i=0;i<n-1;i++)
       {
           if(a[i]!=a[i+1]) num+=1;

       }
       printf("%d",num);

    return 0;
}
