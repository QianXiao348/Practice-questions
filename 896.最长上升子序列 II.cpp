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
const int N = 1e5+10;
int n;
int a[N];
int f[N],cnt;
int main(){
	PASE;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[++cnt]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]<f[cnt])
			f[++cnt]=a[i];
		else 
			*lower_bound(f+1,f+1+cnt,a[i])=a[i];
	}
	cout<<cnt<<endl;
	return 0;
}

