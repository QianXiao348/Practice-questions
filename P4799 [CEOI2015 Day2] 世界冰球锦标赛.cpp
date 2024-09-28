#include<bits/stdc++.h> //折半搜索（双向） 
#include<unordered_map>
using namespace std;
#define FASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const double PI = 3.1415926;
const int mod = 1e9+7;
const double eps = 1e-6;
const int N =50;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
LL n,m;
LL w[N];
LL ans;
LL a[1<<22],b[1<<22];
LL cnta,cntb;
void dfs(LL l,LL r,LL sum,LL a[],LL &cnt){
	if(sum>m) return;
	if(l>r){
		a[++cnt]=sum;
		return;
	}
	dfs(l+1,r,sum+w[l],a,cnt); //选 
	dfs(l+1,r,sum,a,cnt); //不选 
}
int main()
{
	FASE;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	LL mid=n>>1;
	dfs(1,mid,0,a,cnta); //将搜索内容分成两部分并存在两个数组中存起来 
	dfs(mid+1,n,0,b,cntb); 
	sort(a+1,a+1+cnta); //将其中一个结果数组进行排序 
	for(int i=1;i<=cntb;i++){ //然后利用关系对排序的数组进行二分查找答案 
		ans+=upper_bound(a+1,a+1+cnta,m-b[i])-a-1;
	}
	cout<<ans<<endl;
	return 0;
}

