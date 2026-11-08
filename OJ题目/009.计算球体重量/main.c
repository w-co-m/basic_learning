#include <stdio.h>
#include<math.h>
#define  PI  3.1415926
float M(int d,float p)
{
    float r=(float)d/2/10;
    float m=4.0/3*PI*pow(r,3)*p;
    return  m;
}
int main()
{
   int d_Fe,d_Au;
   float M_Fe,M_Au;
   scanf("%d %d",&d_Fe,&d_Au);
   float p_Fe=7.86,p_Au=19.3;
   M_Fe=M(d_Fe,p_Fe);
   M_Au=M(d_Au,p_Au);
   printf("%.3f %.3f",M_Fe,M_Au);
    return 0;
}
