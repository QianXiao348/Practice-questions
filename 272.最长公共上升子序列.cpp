#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 3010;
int n,m;
int a[N],b[N];
int f[N][N];//f[i][j]:����a��ǰi�����֣�����b��ǰj�����֣�����b[i]��β�������з����� 
int ans; 
int main(){
	PASE;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		int maxv=1;//������������һ��a[i]==b[j],LCIS������1
		for(int j=1;j<=m;j++){
			f[i][j]=f[i-1][j];
			if(a[i]==b[j]) f[i][j]=max(f[i][j],maxv); //����ʱ ���´� 
			if(a[i]>b[j]) maxv=max(maxv,f[i-1][j]+1);//��һ���������洢��һ���׶ε��ܹ�����a[i]ǰ�������״ֵ̬ 
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans, f[n][i]);
	cout<<ans<<endl;
	return 0;
}
