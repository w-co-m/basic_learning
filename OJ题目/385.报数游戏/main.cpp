#include <stdio.h>
int judge(int a){
	int flag=0;
	if (a%7==0){
		flag=1;
	}
	while (a!=0){
		if (a%10==7){
			flag=1;
			break;
		}
		else{
			a/=10;
		}
	}
	return flag;
}
int main(){
	int i=1,n,jump1=0,jump2=0,jump3=0,d=0;
	scanf("%d", &n);
	while (i!=n+d+1){
		if (judge(i)){
			if (i%3==1){
				jump1+=1;
			}
			else if (i%3==2){
				jump2+=1;
			}
			else {
				jump3+=1;
			}
			d+=1;
		}
		i++;
	}
	printf("%d %d %d", jump1, jump2, jump3);
	return 0;
}
