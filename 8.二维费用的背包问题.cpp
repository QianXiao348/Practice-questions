#include<bits/stdc++.h>//二维费用 01背包
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 1010, M = 110;
int n,mv,mw;
int v[N],w[N],m[N];
int f[M][M];//f[j][k]:花费1不超过j,花费2不超过k的最大价值 
int main(){
	PASE;
	cin>>n>>mv>>mw;
	for(int i=1;i<=n;i++) cin>>v[i]>>m[i]>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=mv;j>=v[i];j--){
			for(int k=mw;k>=m[i];k--){
				f[j][k]=max(f[j][k],f[j-v[i]][k-m[i]]+w[i]);
			}
		}
	}
	cout<<f[mv][mw]<<endl;
	return 0;
}

