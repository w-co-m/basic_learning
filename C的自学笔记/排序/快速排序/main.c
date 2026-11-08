#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int*b)
{int temp=*a;
*a=*b;
*b=temp;
}

int PartSort(int *arr,int left,int right)
{int key=left;
while(left<right)
{
while(left<right&&arr[right]>=arr[key])
{
    right--;
}
while(left<right&&arr[left]<=arr[key])
{
   left++;
}
swap(&arr[left],&arr[right]);
}
swap(&arr[key],&arr[left]);
key=left;
return left;
}

void Qsort(int *arr,int begin,int end)
{
    if(begin>=end){return;}
    int key=PartSort(arr,begin,end);
    Qsort(arr,begin,key-1);
    Qsort(arr,key+1,end);
}

void PrintArr(int*arr,int n)
{
for(int i=0;i<n;i++)
{
    printf("%d",arr[i]);
}
printf("\n");
}
int main()
{int ar[10]={2,4,1,8,6,0,7,9,3,5};
int sz=sizeof(ar)/sizeof(int);
Qsort(ar,0,sz-1);
PrintArr(ar,sz);
    return 0;
}
