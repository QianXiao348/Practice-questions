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
const int N = 2e4+10;
int m,n;
int v[N];
int f[N];
int main(){
	PASE;
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+v[i]);
	}
	cout<<m-f[m]<<endl;
	return 0;
}

