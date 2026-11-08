#include <stdio.h>

int main()
{
    int score=0,x[1000],count=1;;
    for (int i=0;i<1000;i++)
       {
           scanf("%d",&x[i]);
           if (x[i]==0){break;}
           else{count++;}
       }
    for(int j=0;j<count;j++)
    {
        if(x[j]==1){score++;}
        else if(x[j]==2)
        {
            int count1=0;
            for(int m=j;m>=0;m--)
            {
                if(x[m]==2)
                    count1++;
                else break;
            }
          score+=2*count1;
        }
    }
 printf("%d",score);
    return 0;
}
