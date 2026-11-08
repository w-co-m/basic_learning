#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,x[30];
   scanf("%d",&n);
   if(n%2==1)
   {
       for(int i=0;i<n;i++)
       {
           x[i]=(n*n)+(i-(n/2))*2;
       }
   }
  else if(n%2==0)
   {
       for(int i=0;i<n;i++)
       {
           x[i]=(n*n)-1+(i+1-(n/2))*2;
       }
   }
   for(int j=0;j<n;j++)
    printf("%d ",x[j]);
   printf("\n");
    return 0;
}
