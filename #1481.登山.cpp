#include<bits/stdc++.h>//Lis:贪心+二分法 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 1010;
int n;
int a[N];
int f[N],f1,p1[N];
int g[N],g1,p2[N];
int main(){
	PASE;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	//正向 
	f[++f1]=a[1];
	p1[1]=1;
	for(int i=2;i<=n;i++)
		if(a[i]>f[f1]){
			f[++f1]=a[i];
			p1[i]=f1;
		}
		else {
			int t=lower_bound(f+1,f+1+f1,a[i])-f;
			f[t]=a[i];
			p1[i]=t;
		}
	//反向 
	g[++g1]=a[n];
	p2[n]=1;
	for(int i=n-1;i>=1;i--)
		if(a[i]>g[g1]){
			g[++g1]=a[i];
			p2[i]=g1;
		}
		else{
			int t=lower_bound(g+1,g+1+g1,a[i])-g;
			g[t]=a[i];
			p2[i]=t;
		}
	int res=0;
	for(int i=1;i<=n;i++)
		res=max(res,p1[i]+p2[i]-1);
	cout<<res<<endl;
	return 0;
}

