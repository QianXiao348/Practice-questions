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
const int N = 3010;
int n,m;
int a[N],b[N];
int f[N][N];//f[i][j]:考虑a中前i个数字，考虑b中前j个数字，且以b[i]结尾的子序列方案数 
int ans; 
int main(){
	PASE;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		int maxv=1;//最起码命中了一个a[i]==b[j],LCIS最少是1
		for(int j=1;j<=m;j++){
			f[i][j]=f[i-1][j];
			if(a[i]==b[j]) f[i][j]=max(f[i][j],maxv); //公共时 更新答案 
			if(a[i]>b[j]) maxv=max(maxv,f[i-1][j]+1);//用一个变量，存储上一个阶段的能够接在a[i]前面的最大的状态值 
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans, f[n][i]);
	cout<<ans<<endl;
	return 0;
}
