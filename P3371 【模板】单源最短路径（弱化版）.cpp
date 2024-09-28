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
const int N = 5e5+10, M = 1e4+10;
int n,m,s;
int h[N],w[N],e[N],ne[N],idx;
int dist[M],st[M];
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dijkstra(int x){
	memset(dist,0x3f,sizeof dist);
	priority_queue<PII,vector<PII>,greater<PII>>q;
	dist[x]=0;
	q.push({0,x});
	while(q.size()){
		auto t=q.top();
		q.pop();
		if(st[t.se]) continue;
		st[t.se] = true;
		for(int i=h[t.se];~i;i=ne[i]){
			int j=e[i];
			if(dist[j]>dist[t.se]+w[i]){
				dist[j]=dist[t.se]+w[i];
				q.push({dist[j],j});
			}
		}
	}
}
void solve(){
	cin>>n>>m>>s;
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	dijkstra(s);
	for(int i=1;i<=n;i++){
		if(dist[i]==0x3f3f3f3f) cout<<2147483647<<" ";
		else cout<<dist[i]<<" ";
	}
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


