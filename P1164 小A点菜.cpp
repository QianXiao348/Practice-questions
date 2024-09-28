#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[110];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	vector<int>dp(m+1,0);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	 for(int j=m;j>=a[i];j--)
	   dp[j]=dp[j]+dp[j-a[i]];
	printf("%d",dp[m]);
	return 0;
}

