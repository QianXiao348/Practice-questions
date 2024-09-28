#include<bits/stdc++.h> //kmp+状态机 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 55;
int f[N][N];//密码已生成i位,并且第i位匹配到子串p的位置是j的所有方案
int ne[N];
char s[N];
int n;
void get_next(){
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[i]!=s[j+1]){
			j=ne[j];
		}
		if(s[i]==s[j+1]) j++;
		ne[i]=j;
	}
}
void solve(){
	cin>>n>>s+1;
	int m=strlen(s+1);
	get_next();
	f[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(char ch='a';ch<='z';ch++){
				int u=j;
				while(u&&ch!=s[u+1]){
					u=ne[u];
				}
				if(ch==s[u+1]) u++;
				if(u<m) f[i+1][u]=(f[i+1][u]+f[i][j])%MOD;
			}
		}
	}
	int res=0;
	for(int i=0;i<m;i++) res=(res+f[n][i])%MOD;
	cout<<res<<endl;  
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


