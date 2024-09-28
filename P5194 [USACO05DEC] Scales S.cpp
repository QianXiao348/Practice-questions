#include<bits/stdc++.h>
using namespace std;
#define FASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 5e5+10;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n,c;
LL s[N],ans,a[N];
void dfs(int x,LL sum){
	if(sum+s[x]<=ans) 
		return;
	ans=max(ans,sum);
	for(int i=x;i;i--){
	    if(sum+a[i]<=c)
	        dfs(i-1,sum+a[i]);
	}
	
	
}
int main()
{
	FASE;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>c) {
			n=i-1;
			break;
		}
		s[i]=s[i-1]+a[i];
	}
	dfs(n,0);
	cout<<ans<<endl;
	return 0;
}

