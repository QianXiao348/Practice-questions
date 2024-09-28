#include<stdio.h>
int main()
{
	int m,t,s,sum1,sum;
	scanf("%d %d %d",&m,&t,&s);
	if(t!=0&&s%t!=0)
	{
	 sum1=s/t+1;
	 sum=m-sum1;
	 }
	if(t!=0&&s%t==0)
	{
	sum1=s/t;
	sum=m-sum1;
	}
	if(sum<0)
	 {
	 	sum=0;
	 }
	 if(t==0)
	 {
	 	sum=0;
	 }
	printf("%d",sum);
	return 0;
}
