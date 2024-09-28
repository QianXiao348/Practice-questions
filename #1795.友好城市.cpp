#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 5010;
int f[N],f1;
int n;
PII a[N];
int main(){
	PASE;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
	sort(a+1,a+1+n);
	f[++f1]=a[1].se;
	for(int i=2;i<=n;i++)
		if(a[i].se>f[f1]) f[++f1]=a[i].se;
		else *lower_bound(f+1,f+1+f1,a[i].se)=a[i].se;
	cout<<f1<<endl;
	return 0;
}

