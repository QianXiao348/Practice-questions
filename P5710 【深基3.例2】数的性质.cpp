#include<stdio.h>
int main()
{
	int x,sum1,sum2;
	scanf("%d",&x);
	if(x%2==0)
	 sum1=1;
	else
	 sum1==0;
	if(x<=12&&x>4) 
	  sum2=1;
	else
	  sum2=0;
	if(sum1==1&&sum2==1)
	  printf("1 1 0 0");
	if(sum1==1&&sum2==0)
	  printf("0 1 1 0");
	if(sum1==0&&sum2==0)
	  printf("0 0 0 1");
	if(sum1==0&&sum2==1)
	  printf("0 1 1 0");
	return 0;
}
