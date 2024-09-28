#include<bits/stdc++.h> //LIS:dp 
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
int a[N],f[N];
int main(){
	PASE;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]<a[i]){
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	cout<<*max_element(f+1,f+1+n)<<endl;
	return 0;
}

