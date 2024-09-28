#include<bits/stdc++.h>
using namespace std;
#define FASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const double PI = 3.1415926;
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 1e8+10;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n,q;
int primes[N],cnt;
bool st[N];
void get_primes(){
	for(int i=2;i<=n;i++){
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]<=n/i;j++){
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
int main()
{
	FASE;
	cin>>n>>q;
	get_primes();
	while(q--){
		int x;
		cin>>x;
		cout<<primes[x-1]<<endl;
	}
	return 0;
}

