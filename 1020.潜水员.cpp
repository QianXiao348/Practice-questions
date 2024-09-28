#include<bits/stdc++.h> //至少的二维费用背包问题 
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
int m1,m2,n;
int f[N][N];//f[j][k]:花费1不少于j,花费2不少于k的最小价值 
void solve(){
	cin>>m1>>m2>>n;
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		for(int j=m1;j>=0;j--)
			for(int k=m2;k>=0;k--)
				f[j][k]=min(f[j][k],f[max(0,j-a)][max(0,k-b)]+c);
	}
	cout<<f[m1][m2]<<endl;
}
int main(){
	PASE;
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}


