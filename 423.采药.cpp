#include<bits/stdc++.h> //01±³°ü 
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
int v[N],w[N];
int f[N];
int main(){
	PASE;
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=m;i++) cin>>v[i]>>w[i]; 
	for(int i=1;i<=m;i++){
		for(int j=t;j>=v[i];j--){
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	}
	cout<<f[t];
	return 0;
}

