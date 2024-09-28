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
const int N = 50;
int a[N][N];
void solve(){
	int n;
	cin>>n;
	a[0][n/2]=1;
	int x=0,y=n/2;
	for(int i=2;i<=n*n;i++){
		if(x==0&&y!=n-1){
			a[n-1][y+1]=i;
			x=n-1,y=y+1;
		}
		else if(x!=0&&y==n-1){
			a[x-1][0]=i;
			x=x-1,y=0;
		}
		else if(x==0&&y==n-1){
			a[x+1][y]=i;
			x=x+1;
		}
		else if(x!=0&&y!=n-1){
			if(a[x-1][y+1]==0&&x-1>=0&&y+1<n){
				a[x-1][y+1]=i;
				x=x-1,y=y+1;
			}
			else{
				a[x+1][y]=i;
				x=x+1;	
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	PASE;
	int _;
	_=1;
	while(_--){
		solve();
	}
	return 0;
}


