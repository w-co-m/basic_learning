#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
 int a[10]={3,7,1,9,0,8,4,2,6,5};
  for(int i=0;i<9;i++){
    int min_index=i;
    for(int k=i+1;k<10;k++){
        if(a[min_index]>a[k]){min_index=k;}
    }
    if(min_index!=i){swap(&a[min_index],&a[i]);}

  }
  for (int n=0;n<10;n++){printf("%d\t",a[n]);}
    return 0;
}
