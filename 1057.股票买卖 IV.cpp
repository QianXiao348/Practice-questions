#include<bits/stdc++.h>//[两态三维状态机]
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1e5+10, M = 110;
int w[N];
int f[N][M][2];//表示前i天中交易次数最多是j,且状态是k的最大利润(0未持股，1持股) 
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>w[i];
	memset(f,-0x3f,sizeof f);
	for(int i=0;i<=n;i++) f[i][0][0]=0;
	for(int j=0;j<=k;j++) f[0][j][0]=0;
	for(int i=1;i<=n;i++){
	    for(int j=0;j<=k;j++){
	        if(j) f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][1]+w[i]);
            f[i][j][1]=max(f[i-1][j][1],f[i-1][j][0]-w[i]);
	   }
	}
	cout<<f[n][k][0]<<endl;
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


