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
const int N = 220;
int n,n_a,n_b;
int a[N],b[N];
int win[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};

void solve(){
	cin>>n>>n_a>>n_b;
	for(int i=0;i<n_a;i++) cin>>a[i];
	for(int i=0;i<n_b;i++) cin>>b[i];
	int res_a=0,res_b=0;
	for(int i=0;i<n;i++){
		res_a+=win[a[i%n_a]][b[i%n_b]];
		res_b+=win[b[i%n_b]][a[i%n_a]];
	}
	cout<<res_a<<" "<<res_b;
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


