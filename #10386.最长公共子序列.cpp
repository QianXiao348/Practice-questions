#include<bits/stdc++.h> //LCS
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 1010;
int n,m;
int f[N][N];//以a[i]结尾,b[j]结尾的最长公共子序列长度 
int s1[N],s2[N];
int main(){
	PASE;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s1[i];
	for(int i=1;i<=m;i++) cin>>s2[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]); //不选a[i]选b[j]或者选a[i]不选b[j] 
			if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1; //都选 
		}
	}	
	cout<<f[n][m];
	return 0;
}

