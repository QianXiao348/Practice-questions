#include<bits/stdc++.h> //[��̬��ά״̬��]
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1e5+10;
int w[N];
int f[N][2];//����ǰi��Ĺ��У���i������й�Ʊ״̬Ϊj(j=0 δ�ֹɣ�j=1 �ֹ�)
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
/*��Ϊf[0][1]������ǰ0�죬״̬���Ѿ����룬����һ�����Ϸ�״̬��
(һ�㲻�Ϸ���״̬����ΪINF����-INF��Ҫ��ȡ���ֵ����Сֵ)*/
	f[0][1]=INT_MIN;
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]+w[i]);
		f[i][1]=max(f[i-1][1],f[i-1][0]-w[i]);
	}
	cout<<f[n][0]<<endl;
}
int main(){
	PASE;
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}


