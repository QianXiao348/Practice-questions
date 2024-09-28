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
const int N = 2e5+10;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int fa[N];
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	FASE;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	while(m--){
		int x,y,z;
		cin>>z>>x>>y;
		int a=find(x),b=find(y);
		if(z==1){
			fa[a]=b;
		}
		if(z==2){
			if(a==b) cout<<'Y'<<endl;
			else cout<<'N'<<endl;
		}
	}
	return 0;
}

