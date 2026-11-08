#include<stdio.h>
int main(){
float salary,tax;
scanf_s("%f", &salary);
if (salary <= 3000)
{
	tax = salary * 0.005;
}
else if (salary <= 5000)
{
	tax = salary  * 0.01;
}
else if (salary <= 10000)
{
	tax =  salary * 0.015;
}
else
{
	tax = salary  * 0.02;
}
printf("%.1f\n", tax);
return 0;
}