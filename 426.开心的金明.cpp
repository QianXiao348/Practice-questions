#include<bits/stdc++.h> //01±³°ü 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1e5+10;
int n,m; 
int f[30010];
void solve(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int v,w;
		cin>>v>>w;
		for(int j=m;j>=v;j--)
			f[j]=max(f[j],f[j-v]+v*w);
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


