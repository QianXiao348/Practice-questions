#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1e5+10;
int n,k;
int a[N];
bool check(int x){
	int t=0;
	for(int i=1;i<=n;i++)
		t+=a[i]/x;
	if(t>=k) return true;
	else return false;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=0,r=1e8+10;
	while(l<=r&&r!=0){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r<<endl;
}
int main(){
	PASE;
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}


