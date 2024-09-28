#include<stdio.h>
int main()
{
	int n,i,j,c;
	scanf("%d",&n);
	c=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			printf("%02d",c);
			c++;
			
		}
		printf("\n");
	}
	return 0;
 } 
