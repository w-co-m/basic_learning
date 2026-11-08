#include<stdio.h>
int main(void)
{
	float a = 0;
	float b = 0;
	float c = 0;
	printf("请输入第一个数字：");
	scanf_s("%f", &a);
	printf("请输入第二个数字：");
	scanf_s("%f", &b);
	printf("请输入第三个数字：");
	scanf_s("%f", &c);
	float s = 0;
	s = (a + b + c) / 3;
	printf("%.2f\n", s);
	return 0;
}