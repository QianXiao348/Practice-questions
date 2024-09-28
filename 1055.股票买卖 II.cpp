#include<bits/stdc++.h> //[两态二维状态机]
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
int w[N];
int f[N][2];//考虑前i天的股市，第i天的手中股票状态为j(j=0 未持股，j=1 持股)
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
/*因为f[0][1]代表考虑前0天，状态是已经买入，这是一个不合法状态。
(一般不合法的状态设置为INF或者-INF，要看取最大值或最小值)*/
	f[0][1]=INT_MIN;
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]+w[i]);
		f[i][1]=max(f[i-1][1],f[i-1][0]-w[i]);
	}
	cout<<f[n][0]<<endl;
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


