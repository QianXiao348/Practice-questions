#include<bits/stdc++.h> //树状数组+dp+离散化 
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
int n,a[N];
int b[N],bl;// 离散化数组
LL tr[N],ans;
int lowbit(int x)
{
	return x&-x;
}
void add(int x,LL c){
	for( ;x<=bl;x+=lowbit(x)){
		tr[x]=max(tr[x],c);
	}
}
LL querty(int x){//用于获取当前元素位置之前的所有可能子序列的最大和
	LL res=0;
	for( ; x; x-=lowbit(x))
		res=max(res,tr[x]);
	return res;
}
int main(){
	PASE;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	bl=unique(b+1,b+1+n)-b;
	for(int i=1;i<=n;i++){
		int k=lower_bound(b+1,b+1+bl,a[i])-b;
		LL f=a[i]+querty(k-1); //dp中f[i]=a[i]+max(f[j]) 
		ans=max(ans,f); //更新答案最大值 
		add(k,f); //更新树状数组 使得后续查询能包含当前元素。
	}
	cout<<ans<<endl;
	return 0;
}

