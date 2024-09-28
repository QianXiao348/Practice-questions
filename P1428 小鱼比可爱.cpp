#include<stdio.h>
int main()
{
	int a[101],n,i,j;
	int count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	printf("0");
	for(i=1;i<n;i++)
	{
		count=0;
		for(j=0;j<i;j++)
		{
		if(a[i]>a[j])
		count++;
	    }
		printf(" %d",count);
	}
	return 0;
}
