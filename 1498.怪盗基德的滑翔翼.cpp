#include<bits/stdc++.h> //LIS:贪心+二分优化 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 110;
int a[N];
int f[N],g[N],cnt1,cnt2;
int main(){
	PASE;
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		f[++cnt1]=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]>f[cnt1]) f[++cnt1]=a[i];
			else *lower_bound(f+1,f+1+cnt1,a[i])=a[i];
		} 
		int res=cnt1;
		g[++cnt2]=a[n];
		for(int i=n-1;i>=1;i--){
			if(a[i]>g[cnt2]) g[++cnt2]=a[i];
			else *lower_bound(g+1,g+1+cnt2,a[i])=a[i];
		}
		res=max(res,cnt2);
		cout<<res<<endl;
	} 
	return 0;
}

