#include<bits/stdc++.h>//״ѹdp
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
int f[2][M][M];//����ǰi��(���������Ż���Ϊ2)����i-1��״̬��j����i��״̬��k�ķ���
int cnt[N];
int count(int x) //1�ĸ���
{
	int res=0;
	while(x)
	{
		x=x&(x-1);
		res++;
	}
	return res;
}
bool check(int x)  //����3���ڲ��ܳ��ֳ���1��1
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
			if(c=='H') g[i]|=1<<j;//�ڵ�i�еĵ�j�еĶ����Ʊ�Ϊ1
		}
	for(int i=0; i<1<<m; i++)//Ԥ��������״̬ 
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
					if(a&b|a&c|b&c) continue; //ͬ��3���ڲ��ܳ��ֳ���1��1 
					if(g[i-1]&a|g[i]&b) continue; //ȷ�������а���Ŀȷ����Щ�ط����ܳ���1 
					f[i&1][k][j]=max(f[i&1][k][j],f[i-1&1][u][k]+cnt[b]);//&1�ǹ��������Ż� ����״̬���±��ʡ�ռ� 
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


