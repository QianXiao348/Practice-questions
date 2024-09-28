#include<bits/stdc++.h>//状压dp
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]= {-1,0,1,0,-1,1,1,-1};
const int dy[]= {0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 110, M= 1<<10;
int n,m;
vector<int>state;
int g[N];
int f[2][M][M];//摆完前i行(滚动数组优化后为2)，且i-1行状态是j，第i行状态是k的方案
int cnt[N];
int count(int x) //1的个数
{
	int res=0;
	while(x)
	{
		x=x&(x-1);
		res++;
	}
	return res;
}
bool check(int x)  //连续3格内不能出现超过1个1
{
	return !(x&x>>1||x&x>>2);
}
void solve()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=0; j<m; j++)
		{
			char c;
			cin>>c;
			if(c=='H') g[i]|=1<<j;//在第i行的第j列的二进制标为1
		}
	for(int i=0; i<1<<m; i++)//预处理所有状态 
		if(check(i))
		{
			state.push_back(i);
			cnt[i]=count(i);
		}
	for(int i=1; i<=n; i++)
		for(int j=0; j<state.size(); j++) //i
			for(int k=0; k<state.size(); k++) //i-1
				for(int u=0; u<state.size(); u++) //i-2
				{
					int a=state[k],b=state[j],c=state[u];
					if(a&b|a&c|b&c) continue; //同列3格内不能出现超过1个1 
					if(g[i-1]&a|g[i]&b) continue; //确定的两行按题目确定哪些地方不能出现1 
					f[i&1][k][j]=max(f[i&1][k][j],f[i-1&1][u][k]+cnt[b]);//&1是滚动数组优化 储存状态的下标更省空间 
				}
	int res=0;
	for(int j=0; j<state.size(); j++) //i
		for(int k=0; k<state.size(); k++) //i-1
			res=max(res,f[n&1][k][j]);
	cout<<res<<endl;
}
int main()
{
	PASE;
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}


