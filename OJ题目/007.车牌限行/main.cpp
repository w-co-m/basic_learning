#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day,level,num,last;

    scanf("%d %d %d",&day,&level,&num);
    last=num%10;
    if(day==6||day==7||level<200)
        printf("%d  no\n",last);
    if(level>=200&&level<400)
    {
        if(day==1)
        {
         if(last==1||last==6) printf("%d  yes\n",last);
         else printf("%d  no\n",last);
        }
        else if(day==2)
        {
         if(last==2||last==7) printf("%d  yes\n",last);
         else printf("%d  no\n",last);
        }
       else if(day==3)
        {
         if(last==3||last==8) printf("%d  yes\n",last);
         else printf("%d  no\n",last);
        }
        else if(day==4)
        {
         if(last==4||last==9) printf("%d  yes\n",last);
         else printf("%d  no\n",last);
        }
        else if(day==5)
        {
         if(last==5||last==0) printf("%d  yes\n",last);
         else printf("%d  no\n",last);
        }

    }
    if(level>=400)
        {
            if(day==1||day==3||day==5)
            {
                if(last==1||last==3||last==5||last==7||last==9) printf("%d  yes\n",last);
                else printf("%d  no\n",last);
            }
            else if(day==2||day==4)
            {
                 if(last==0||last==2||last==4||last==6||last==8) printf("%d  yes\n",last);
                else printf("%d  no\n",last);
            }
        }

    return 0;
}
