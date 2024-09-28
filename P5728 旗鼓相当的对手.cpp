#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1010;
struct Node{
	int x,y,z,sum;
}a[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].sum=a[i].x+a[i].y+a[i].z;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(abs(a[i].x-a[j].x)<=5&&abs(a[i].y-a[j].y)<=5&&abs(a[i].z-a[j].z)<=5&&abs(a[i].sum-a[j].sum)<=10)
				ans++;
	cout<<ans<<endl;
}
int main(){
	PASE;
	solve();
	return 0;
}


