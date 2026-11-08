#include <stdio.h>

int is_Prime(int x)
{
    if(x==1) return 0;
    for(int i=2;i<x;i++)
        {if(x%i==0)  return 0;}
    return 1;
}
int main()
{
    int a,b,sum=0,arr[100]={},count=0,x=2;
    scanf("%d %d",&a,&b);
    if(a>b)
    {
        int temp=a; a=b ;b=temp;
    }
    while(count<b)
    {
        if(is_Prime(x))
        {
            arr[count]=x;
            count++;
        }
        x++;
    }
    for(int i=a-1;i<b;i++)
    {
        sum+=arr[i];
    }
    printf("%d",sum);
    return 0;
}
