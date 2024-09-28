	#include<iostream> //并查集+反集 
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
	const int N = 3010;
	int n,m;
	int fa[N];
	int find(int x){
		if(x!=fa[x]) fa[x]=find(fa[x]);
		return fa[x];
	}
	void solve(){
		cin>>n>>m;
		for(int i=1;i<=n*2;i++) fa[i]=i;
		while(m--){
			char ch;
			int p,q;
			cin>>ch>>p>>q;
			if(ch=='F'){
				fa[find(p)]=find(q);
			}
			else{
				fa[find(p+n)]=find(q); //反集 
				fa[find(q+n)]=find(p); 
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(fa[i]==i) ans++;
		cout<<ans<<endl;
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
	

