#include<iostream>//¶àÖØ±³°ü1 
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
const int N = 1e5;
int n,m; 
int f[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int v,w,s;
		cin>>v>>w>>s;
		for(int j=m;j>=v;j--)
			for(int k=0;k<=s;k++)
				if(k*v<=j)
					f[j]=max(f[j],f[j-v*k]+k*w);
	}
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


