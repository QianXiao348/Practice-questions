#include<iostream>//¸ß¾«¶È³Ë 
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
const int N = 5010;
int A[N],B[N],c[N];
int al,bl,cl;
void mul(int a[],int &al,int b[],int &bl){
	cl=al+bl;
	for(int i=1;i<=al;i++)
		for(int j=1;j<=bl;j++)
			c[i+j-1]+=a[i]*b[j];
	int t=0;
	for(int i=1;i<=cl;i++){
		t+=c[i];
		c[i]=t%10;
		t/=10;
	}
	while(cl>1&&c[cl]==0) cl--;
}
void solve(){
	string a,b;
	cin>>a>>b;
	al=a.size(),bl=b.size();
	for(int i=a.size()-1;i>=0;i--) A[a.size()-i]=(a[i]-'0');
	for(int i=b.size()-1;i>=0;i--) B[b.size()-i]=(b[i]-'0');
	mul(A,al,B,bl);
	for(int i=cl;i>=1;i--) cout<<c[i];
}
int main(){
	PASE;
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}


