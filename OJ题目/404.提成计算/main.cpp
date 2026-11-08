#include <stdio.h>
#include <stdlib.h>

int main()
{
    int level,performance;
    float  basic_salary,extra_salary,rate;
    scanf("%d %d",&level,&performance);
    if(level==1)
        {basic_salary=50000.0;
   rate=0.03; }
    else   if(level==2)
        {basic_salary=35000.0;
    rate=0.02;}
    else   if(level==3)
        {basic_salary=20000.0;
    rate=0.02;}
    else   if(level==4)
        {basic_salary=5000.0;
    rate=0.025;}
    if (performance>basic_salary)
    {
        extra_salary=((float)performance-basic_salary)*rate;
    }
    printf("%d %.1f  %.1f",level,basic_salary,extra_salary);
    return 0;
}
