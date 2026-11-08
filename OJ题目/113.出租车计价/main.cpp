#include <stdio.h>


int main()
{
    int  time,mon;
    float   s;
    scanf("%f %d",&s,&time);
    mon=(time/5)*2;
    if(s<3)
        mon+=10;
    else   if(s<=10)
        mon=mon+10+(s-3)*2;
    else
        mon=mon+24+(s-10)*3;
    int money=(int)(mon+0.5);
    printf("%d",money);
    return 0;
}
