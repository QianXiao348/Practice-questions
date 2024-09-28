#include<bits/stdc++.h> //离散化+并查集 
using namespace std;
#define FASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const double PI = 3.1415926;
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 1e5+10;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int ls[N*2],fa[N*2];
struct Node{
	LL i,j,e;
}a[N];
bool cml(Node &a,Node &b){
	return a.e>b.e;
}
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	FASE;
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].i>>a[i].j>>a[i].e;
			ls[++cnt]=a[i].i;
			ls[++cnt]=a[i].j;
		}
		sort(ls+1,ls+cnt+1);
		sort(a+1,a+1+n,cml);
		int t=unique(ls+1,ls+cnt+1)-ls-1;
		for(int i=1;i<=n;i++){
			a[i].i=lower_bound(ls+1,ls+t+1,a[i].i)-ls;
			a[i].j=lower_bound(ls+1,ls+t+1,a[i].j)-ls;
			fa[a[i].i]=a[i].i,fa[a[i].j]=a[i].j;
		}
		bool flag=false;
		for(int i=1;i<=n;i++){
			int x1=find(a[i].i);
			int x2=find(a[i].j);
			if(a[i].e) fa[x1]=x2;
			else if(x1==x2){
				flag=true;
				break;	
			}
		}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}

