#include<bits/stdc++.h> //LCS
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 1010;
int n,m;
int f[N][N];//��a[i]��β,b[j]��β������������г��� 
int s1[N],s2[N];
int main(){
	PASE;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s1[i];
	for(int i=1;i<=m;i++) cin>>s2[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]); //��ѡa[i]ѡb[j]����ѡa[i]��ѡb[j] 
			if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1; //��ѡ 
		}
	}	
	cout<<f[n][m];
	return 0;
}

