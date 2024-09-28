#include<bits/stdc++.h> //恰好完全背包 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 20, M = 3010;
int n,m;
int v[N];
LL f[M];
int main(){
	PASE;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	f[0]=1;//恰好 
	for(int i=1;i<=n;i++){
		for(int j=v[i];j<=m;j++)
			f[j]+=f[j-v[i]];
	}
	cout<<f[m];
	return 0;
}

