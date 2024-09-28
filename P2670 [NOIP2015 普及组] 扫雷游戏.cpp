#include<iostream>
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
char g[N][N];
char pd(int x,int y){
	int res=0;
	for(int i=0;i<8;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<1||a>n||b<1||b>m) continue;
		if(g[a][b]=='*') res++;
	}
	return res+'0';
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>g[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j]=='?') g[i][j]=pd(i,j);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<g[i][j];
		cout<<endl;
	}
}
int main(){
	PASE;
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}


