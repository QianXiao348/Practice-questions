#include<bits/stdc++.h>
using namespace std;
#define FASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const double PI = 3.1415926;
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 1e4+10, M = 5e5+10;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n,m,s;
int h[N],e[M],w[M],ne[M],idx;
int dist[N];
bool st[N];
void add(int a,int b,int c){
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}
void dijkstra(){
	for(int i=1;i<=n;i++)
		dist[i]=pow(2,31)-1;
	priority_queue<PII,vector<PII>,greater<PII>>heap;
	dist[s]=0;
	heap.push({0,s});
	while(heap.size()){
		auto t=heap.top();
		heap.pop();
		if(st[t.se]) continue;
		st[t.se]=true;
		for(int i=h[t.se];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>t.fi+w[i]){
				dist[j]=t.fi+w[i];
				heap.push({dist[j],j});
			}
		}
	}
}
int main()
{
	FASE;
	cin>>n>>m>>s;
	memset(h,-1,sizeof h);
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	return 0;
}

