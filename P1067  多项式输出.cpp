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
int n;
void solve(){
	cin>>n;
	for(int i=n;i>=0;i--){
		int a;
		cin>>a;
		if(a){
			if(i!=n&&a>0)	cout<<"+";
			if(a<0) cout<<"-";
			if(abs(a)>1||i==0) cout<<abs(a);
			if(a&&i>1) cout<<"x"<<"^"<<i;
			if(a&&i==1) cout<<"x";
		}
	}
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


