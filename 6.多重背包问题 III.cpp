#include<bits/stdc++.h> //dp+单调队列优化 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 1010, M = 2e4+10;
int n,m;
int g[M],f[M],q[M];
int main()
{
	PASE;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int v,w,s;
		cin>>v>>w>>s;
		memcpy(g,f,sizeof f);
		for(int j=0;j<v;j++)
		{
			int hh=0,tt=-1;
			for(int k=j;k<=m;k+=v)
			{
				if(hh<=tt&&q[hh]<k-s*v) hh++;
				if(hh<=tt) f[k]=max(f[k],g[q[hh]]+(k-q[hh])/v*w);
				while(hh<=tt&&g[q[tt]]-(q[tt]-j)/v*w<=g[k]-(k-j)/v*w) tt--;
				q[++tt]=k;
			}
		}
	}
	cout<<f[m]<<endl;
	return 0;
}

