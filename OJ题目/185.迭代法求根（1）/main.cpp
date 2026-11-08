#include <stdio.h>
#include <stdlib.h>

int main()
{
    double  a,derta=1.0,x0=1.0,x01,x1,x11;
    scanf("%lf",&a);
    while(derta!=0)
    {
        x1=0.5*(x0+a/x0);
        x01=100000*x0;
        x11=100000*x1;
        x0=x1;
        if((int)x01==(int)x11)  derta=0;
    }
    printf("%.5lf",x0);
    return 0;
}
