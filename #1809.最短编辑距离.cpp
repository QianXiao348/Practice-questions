#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 2010;
int f[N][N];//f[i][j]表示把a[1~i]和b[1~j]匹配上需要的最小次数的操作方式
void solve(){
	string a,b;
	cin>>a>>b;
	int n=a.size(),m=b.size();
	a=" "+a,b=" "+b;
	for(int i=0;i<=n;i++) f[i][0]=i; //若b为空，a一直删除 
	for(int j=0;j<=m;j++) f[0][j]=j; //若a为空，a一直增加 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{//先进行增减操作，数量匹配之后进行改的操作
			f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
			if(a[i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);//如果不需要改了，那么上一层基础上加0
			else f[i][j]=min(f[i][j],f[i-1][j-1]+1); //如果需要改，那么就上一层基础上加1
		} 
	cout<<f[n][m];
}
int main(){
	PASE;
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}


