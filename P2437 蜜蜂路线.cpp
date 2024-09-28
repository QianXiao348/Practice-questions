#include<bits/stdc++.h>
using namespace std;
int m,n,len=1;
int dp[1010][1010];
void add(int x){
	for(int i=1;i<=len;i++)
	 dp[x][i]=dp[x-1][i]+dp[x-2][i];
	for(int i=1;i<=len;i++){
		if(dp[x][i]>9){
			dp[x][i+1]+=dp[x][i]/10;
			dp[x][i]%=10;
		}
		if(dp[x][len+1]) len++; 
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	dp[1][1]=1,dp[2][1]=2;
	for(int i=3;i<=n-m;i++)
	 add(i);
	for(int i=len;i>=1;i--)
	  cout<<dp[n-m][i];
	return 0;
}

