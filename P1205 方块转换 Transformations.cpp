#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 15;
int n;
char s1[N][N],s2[N][N],t[N][N];
bool pd(){
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
			if(t[i][j]!=s2[i][j])
				return false;
	return true;
}
void bf(int x){
	if(x==1){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				t[j][n-i+1]=s1[i][j];
	}
	else if(x==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				t[n-i+1][n-j+1]=s1[i][j];
	}
	else if(x==3){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				t[n-j+1][i]=s1[i][j];
	}
	else if(x==4){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				t[i][n-j+1]=s1[i][j];
	}
	else if(x==5){
		bf(4);
		memcpy(s1,t,sizeof t);
		bf(1);
		if(pd()) return;
		memcpy(s1,t,sizeof t);
		bf(2);
		if(pd()) return;
		memcpy(s1,t,sizeof t);
		bf(3);
	}
	else if(x==6){
		return ;
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++){
			cin>>s1[i][j];
		}
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
			cin>>s2[i][j];
	bool flag=false;
	for(int i=1;i<=6;i++){
		memset(t,0,sizeof t);
		bf(i);
		if(pd()){
			cout<<i<<endl;
			flag=true;
			break;
		}
	}
	if(!flag) cout<<7<<endl;
}
int main(){
	PASE;
	int _;
	_=1;
	while(_--){
		solve();
	}
	return 0;
}


