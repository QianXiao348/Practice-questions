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
const int N = 1010;
int n,m;
int v[N],w[N];
int f[N][N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=n;i>=1;i--){ //由于输出字典序输出 所以倒序处理 
		for(int j=0;j<=m;j++){
			f[i][j]=f[i+1][j];
			if(j>=v[i]) f[i][j]=max(f[i][j],f[i+1][j-v[i]]+w[i]);	
		}
	}
	int j=m;
	for(int i=1;i<=n;i++){
		if(j>=v[i]&&f[i][j]==f[i+1][j-v[i]]+w[i]){
			cout<<i<<" ";
		    j-=v[i];
		}
	}
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


