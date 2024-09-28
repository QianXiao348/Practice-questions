#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 110;
int n,m; 
int s[N];
int v[N][N],w[N][N];
int f[N];//f[i][j]:只从前i组物品中选，当前体积小于等于j的最大值
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=s[i];j++)
			cin>>v[i][j]>>w[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--)
			for(int k=1;k<=s[i];k++)
				if(j>=v[i][k]) f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
	}
	cout<<f[m]<<endl;
}
int main(){
	PASE;
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}


