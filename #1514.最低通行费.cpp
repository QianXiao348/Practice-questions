#include<bits/stdc++.h> //线性dp（分析出不走回头路） 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 110;
int a[N][N],dp[N][N];
int main(){
	PASE;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j]; 
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==1&&j==1)
				dp[i][j]=a[i][j];
			else
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
	cout<<dp[n][n]<<endl;
	return 0;
}

