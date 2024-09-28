#include<stdio.h>
int main()
{
	int x,y,i,count,j,a[1000];
	scanf("%d %d",&x,&y);
	count=0;j=0;
	for(i=x;i<=y;i++)
	{
		if((i%4==0&&i%100!=0)||i%400==0)
		count++;
		a[j++]=i;
		//j++;
	}
     printf("%d\n",count);
     for(j=0;j<count;j++)
      printf("%d ",a[j]);
	return 0;
 } 
