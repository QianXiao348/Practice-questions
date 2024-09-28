#include<bits/stdc++.h> //二维费用 01背包
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 1010, M = 510, K = 110;
int n,m,k;
int v[K],w[K];
int f[N][M];//f[j][p]第1维费用不超过j,第2费用不超过p的方案 
int main(){
	PASE;
	cin>>n>>m>>k;
	m--;//留一滴血 
	for(int i=1;i<=k;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
		for(int j=n;j>=v[i];j--)
			for(int p=m;p>=w[i];p--)
				f[j][p]=max(f[j][p],f[j-v[i]][p-w[i]]+1);
	int cost=m;
	for(int i=0;i<=m;i++)
		if(f[n][i]==f[n][m]) 
			cost=min(cost,i);
	cout<<f[n][m]<<" "<<m+1-cost<<endl;
	return 0;
}

