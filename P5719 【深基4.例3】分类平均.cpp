#include<stdio.h>
int main()
{
	int n,k,i,count1,count2,sum1,sum2;
	float average1,average2;
	count1=0;sum1=0;sum2=0;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		if(i%k==0)
		{
			sum1+=i;
			count1++;
		}
		else
		{
		     sum2+=i;
		}
	}
	count2=n-count1;
	average1=(float)sum1/count1;
	average2=(float)sum2/count2;
	printf("%.1f %.1f",average1,average2);
	return 0;
}
