 #include<iostream> //∆”Àÿ∞Ê±æ 
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
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
int v[N],s[N],w[N];
int f[N][N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=s[i];k++)
				if(j>=k*v[i]) f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
	cout<<f[n][m]<<endl;
}
int main(){
	PASE;
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}


