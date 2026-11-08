#include <stdio.h>
#include<math.h>
int main()
{
 int n,a[1000],min,diference_value;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
     scanf("%d",&a[i]);
 }
min=abs(a[0]-a[1]);
 for(int i=0;i<n;i++)
 {
     for(int j=i+1;j<n;j++)
     {
         diference_value=abs(a[i]-a[j]);
         if(diference_value<min) min=diference_value;
     }

 }
 printf("%d",min);
    return 0;
}
