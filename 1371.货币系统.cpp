#include<bits/stdc++.h>//ÍêÈ«±³°ü 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1e4+10;
LL f[N];
void solve(){
	int n,m;
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=x;j<=m;j++){
			f[j]+=f[j-x];
		}
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


