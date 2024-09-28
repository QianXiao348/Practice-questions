#include<bits/stdc++.h> //三态二维状态机
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
int f[N][3];//前i天且状态j的最大利润(0空仓 1满仓 2冷却) 
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	memset(f,-0x3f,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][2],f[i-1][0]);
		f[i][1]=max(f[i-1][1],f[i-1][0]-w[i]);
		f[i][2]=f[i-1][1]+w[i];
	}
	cout<<max(f[n][0],f[n][2])<<endl;
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


