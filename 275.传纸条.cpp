#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 55;
int w[N][N];
int f[N*2][N][N];
int main(){
	PASE;
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>w[i][j];
	for(int k=2;k<=n+m;k++){
		for(int i1=1;i1<=m;i1++){
			for(int i2=1;i2<=m;i2++){
				int j1=k-i1,j2=k-i2;
				if(j1>=1&&j2>=1&&j1<=m&&j2<=m){
					int &x=f[k][i1][i2];
					int t=w[i1][j1];
					if(i1!=i2) t+=w[i2][j2];
					x=max(x,f[k-1][i1-1][i2-1]+t);
					x=max(x,f[k-1][i1-1][i2]+t);
					x=max(x,f[k-1][i1][i2-1]+t);
					x=max(x,f[k-1][i1][i2]+t); 
				}
			}
		}
	}
	cout<<f[n+m][m][m]<<endl;
	return 0;
}

