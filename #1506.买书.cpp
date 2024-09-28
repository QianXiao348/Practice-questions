#include<bits/stdc++.h> //ÍêÈ«±³°ü 
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
int v[]={0,10,20,50,100};
int f[N];
int main(){
	PASE;
	cin>>n;
	f[0]=1;
	for(int i=1;i<=4;i++){
		for(int j=v[i];j<=n;j++){
			f[j]+=f[j-v[i]];			
		}
	}
	cout<<f[n];
	return 0;
}

