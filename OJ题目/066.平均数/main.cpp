#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num,x[1000];
   int sum=0;
   float aran;
   scanf("%d",&num);
   for(int i=0;i<num;i++)
   {
   scanf("%d",&x[i]);
   sum+=x[i];
   }
   aran=(float)sum/num;
   printf("%.2f",aran);
    return 0;
}
