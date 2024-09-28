#include<bits/stdc++.h>
using namespace std;
int n,dp[5010][5010],len;
void add(int k){
	for(int i=1;i<=len;i++)
	 dp[k][i]=dp[k-1][i]+dp[k-2][i];
	for(int i=1;i<=len;i++){
		if(dp[k][i]>=10){
			dp[k][i+1]+=dp[k][i]/10;
			dp[k][i]%=10;
			if(dp[k][len+1]>0) len++;
		}
	}	
} 
int main()
{
	cin>>n;
	len=1;
	dp[1][1]=1;dp[2][1]=2;
	for(int i=3;i<=n;i++)
	  add(i);
	for(int i=len;i>0;i--)
	 cout<<dp[n][i];
    return 0;
}
