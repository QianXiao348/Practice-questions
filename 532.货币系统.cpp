#include<bits/stdc++.h> //完全背包+求方案数
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 110,M = 25010;
int n;
int a[N];
int f[M];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(f,0,sizeof f);
	sort(a+1,a+1+n);
	int m=a[n]; //背包容量
	f[0]=1;
	int res=0;
	for(int i=1;i<=n;i++){
		if(!f[a[i]]) res++;
		for(int j=a[i];j<=m;j++)
			f[j]+=f[j-a[i]];
	}
	cout<<res<<endl;
}
int main(){
	PASE;
	int _=1;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}

