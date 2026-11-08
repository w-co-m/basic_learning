#include <stdio.h>
#include <stdlib.h>
   void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;}
int main()
{
 int a[10]={7,4,8,0,3,5,1,6,2,9};
 for(int i=0;i<9;i++){
    for(int j=0;j<9-i;j++){
        if(a[j]>a[j+1]){
            swap(&a[j],&a[j+1]);
        }
    }
 }
 for(int n=0;n<10;n++){printf("%d",a[n]);}
    return 0;
}
