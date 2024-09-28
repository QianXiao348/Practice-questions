#include<stdio.h>
int main()
{
	int n,a[1000];
	scanf("%d",&n);
	int i=0;
	a[i]=n;
	while(1)
	{
	 if(n%2==0)
	 a[i++]=a[i]/2;
	 else
	 n=n*3+1;
	 if(n==1)
	  break;
    }
}
