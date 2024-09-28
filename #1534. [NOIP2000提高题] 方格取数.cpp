#include<bits/stdc++.h> //ÏßÐÔdp 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 15;
int a[N][N]; 
int n;
int f[N*2][N][N];
int main(){
	PASE;
	cin>>n;
	int x,y,z;
	while(cin>>x>>y>>z,x||y||z) a[x][y]=z;
	for(int k=2;k<=2*n;k++){
		for(int i1=1;i1<=n;i1++){
			for(int i2=1;i2<=n;i2++){
				int j1=k-i1,j2=k-i2;
				if(j1>=1&&j2>=1&&j1<=n&&j2<=n){
					int t=a[i1][j1];
					if(i1!=i2) t+=a[i2][j2];
					int &x=f[k][i1][i2];
					x=max(x,f[k-1][i1-1][i2-1]+t);
					x=max(x,f[k-1][i1-1][i2]+t);
					x=max(x,f[k-1][i1][i2-1]+t);
					x=max(x,f[k-1][i1][i2]+t);
				}
			}
		}
	}
	cout<<f[n*2][n][n]<<endl;
	return 0;
}

