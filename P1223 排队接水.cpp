#include<bits/stdc++.h>
using namespace std;
//每个人接水会导致后面所有人等待 而接水完后人人就不需要等待
//先排序后 计算时第i个人当前接水都会导致n-i个人等待  所有等待时间和/n即可 
struct que{
	int t,k;
}a[1010];
bool cnm(que b,que c)
{
	return b.t<c.t;
}
int main()
{
	int n,t;
	double ans,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t;
		a[i].k=i;
	}
	sort(a+1,a+n+1,cnm);
	for(int i=1;i<=n;i++){
	    printf("%d ",a[i].k);
	     sum+=(n-i)*a[i].t;
	}
	printf("\n");
	ans=sum/n;
	printf("%.2f",ans);
 } 
