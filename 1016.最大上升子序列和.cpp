#include<bits/stdc++.h>//dp利用LIS的思想 
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
int f[N];
int main(){
	PASE;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int res=0;
	for(int i=1;i<=n;i++){
		f[i]=a[i];
		for(int j=1;j<i;j++)
			if(a[i]>a[j]) f[i]=max(f[i],f[j]+a[i]);
		res=max(res,f[i]);
	}
	cout<<res<<endl;
	return 0;
}

