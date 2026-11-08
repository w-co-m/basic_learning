#include <stdio.h>

void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;}
void   Rank(int a[], int size)
{
 for(int i=0;i<size-1;i++){
    for(int j=0;j<size-1-i;j++){
        if(a[j]<a[j+1]){
            swap(&a[j],&a[j+1]);
        }
    }
 }

}


int main()
{
int a[100],size_a,b[100],c[100],count1=0,count2=0;
scanf("%d",&size_a);
for(int i=0;i<size_a;i++)
    scanf("%d",&a[i]);
for(int i=0;i<size_a;i++)
{
  if(a[i]%2==0)
  {
      b[count1++]=a[i];
  }
  else
  {
      c[count2++]=a[i];
  }
}
  Rank(b,count1);
  Rank(c,count2);
  for(int i=0;i<count1;i++)
    printf("%d ",b[i]);
  for(int i=0;i<count2;i++)
    printf("%d ",c[i]);
    return 0;
}
