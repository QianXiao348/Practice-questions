#include<bits/stdc++.h>
using namespace std;
int n,ans=0,mark=0;
int a[100010];
//f[i]表示第i个坑需要填的次数是多少 
//通过递推发现当a[i-1]>=a[i]时f[i]=f[i-1]; 
//当a[i-1]<a[i]时f[i]=f[i-1]+(a[i-1]-a[i]); 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
     scanf("%d",&a[i]);
     vector<int>f(n+1);
    f[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i-1]>=a[i])
		 f[i]=f[i-1];
		else f[i]=f[i-1]+(a[i]-a[i-1]);
	}
	printf("%d",f[n]); 
	return 0;
 } 
