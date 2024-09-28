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
const int N = 1<<21;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n,mid;
int a[30];
int res,tot;
int ans[N];
vector<int>p[N];
map<int,int>mp;
void dfs1(int x,int sum,int now){//枚举一半的数，记录每一种情况的和。
	if(x>mid){
		if(!mp[sum]) mp[sum]=++tot; //离散化 
		p[mp[sum]].push_back(now); //存下当下方案 
		return ;
	}
	dfs1(x+1,sum+a[x],now|(1<<(x-1))); 
	dfs1(x+1,sum-a[x],now|(1<<(x-1))); 
	dfs1(x+1,sum,now);
}
void dfs2(int x,int sum,int now){ //爆搜另一半，当和为S时，判断前一半是否可以凑出S，如果可以，打个标记即可
	if(x>n){
		auto t=mp[sum];
		if(t)
			for(int i=0;i<p[t].size();i++)
				ans[p[t][i]|now]=1;
		return ;
	}
	dfs2(x+1,sum+a[x],now|(1<<(x-1)));
	dfs2(x+1,sum-a[x],now|(1<<(x-1)));
	dfs2(x+1,sum,now);
}
int main()
{
	FASE;
	cin>>n;
	mid=n>>1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs1(1,0,0);
	dfs2(mid+1,0,0);
	for(int i=1;i<=(1<<n);i++)
		res+=ans[i];
	cout<<res<<endl;
	return 0;
}

