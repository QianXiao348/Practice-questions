#include<stdio.h>
#include<math.h>
int main()
{
	int a,i;
	scanf("%d",&a);
	i=1;
    while(a!=1)
    {
    	floor(a=a/2);
    	i++;
	}
	printf("%d",i);
	return 0;
}
