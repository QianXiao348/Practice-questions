#include<stdio.h>
int main()
{
	int i,n,x,sum=0;
	scanf("%d %d",&n,&x);
	for(i=1;i<=n;i++)
	{
		int m=i;

		while(m)
		{
			int c=m%10;
			 m/=10;
			if(c==x)
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
 } 
