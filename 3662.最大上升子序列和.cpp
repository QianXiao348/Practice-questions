#include<bits/stdc++.h> //��״����+dp+��ɢ�� 
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
int b[N],bl;// ��ɢ������
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
LL querty(int x){//���ڻ�ȡ��ǰԪ��λ��֮ǰ�����п��������е�����
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
		LL f=a[i]+querty(k-1); //dp��f[i]=a[i]+max(f[j]) 
		ans=max(ans,f); //���´����ֵ 
		add(k,f); //������״���� ʹ�ú�����ѯ�ܰ�����ǰԪ�ء�
	}
	cout<<ans<<endl;
	return 0;
}

