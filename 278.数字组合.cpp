#include<bits/stdc++.h> //体积恰好j的01背包问题 f[i][0]=1; 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 110, M = 1e4+10;
int n,m;
int a[N];
int f[M];
int main(){
	PASE;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	f[0]=1;//恰好初始化 
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i];j--){
			f[j]+=f[j-a[i]];
		}
	}
	cout<<f[m]<<endl;
	return 0;
}

