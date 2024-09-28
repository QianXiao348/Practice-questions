#include<bits/stdc++.h> //线性dp（数字三角形模型） 
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
int a[N][N];
int main(){
	PASE;
	int _;
	cin>>_;
	while(_--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>>dp(n+1,vector<int>(m+1,0));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
			}
		cout<<dp[n][m]<<endl;
	} 
	return 0;
}

