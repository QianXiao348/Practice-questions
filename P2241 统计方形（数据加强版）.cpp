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
const int N = 1e5+10;
void solve(){
	int n,m;
	cin>>n>>m;
	LL z=0,c=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			z+=min(i,j);
			c+=(i*j);
		}
	cout<<z<<" "<<c-z<<endl;
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


