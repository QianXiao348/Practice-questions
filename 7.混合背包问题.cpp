#include<iostream> //采用多重背包二进制优化 
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
const int N = 1e5+10;
int n,m;
int v[N],w[N];
int f[N];
void solve(){
	cin>>n>>m;
	int idx=0;
	for(int i=1;i<=n;i++){
		int a,b,s;
		cin>>a>>b>>s;
		if(s==-1) s=1;
		else if(s==0) s=m/a;
		for(int k=1;k<=s;k*=2){
			idx++;
			v[idx]=a*k;
			w[idx]=b*k;
			s-=k;
		}
		if(s){
		    idx++;
			v[idx]=a*s;
			w[idx]=b*s;
		}
	}
	n=idx;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+w[i]);
	cout<<f[m]<<endl;
}
int main(){
	PASE;
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}


