#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 2010;
int f[N][N];//f[i][j]��ʾ��a[1~i]��b[1~j]ƥ������Ҫ����С�����Ĳ�����ʽ
void solve(){
	string a,b;
	cin>>a>>b;
	int n=a.size(),m=b.size();
	a=" "+a,b=" "+b;
	for(int i=0;i<=n;i++) f[i][0]=i; //��bΪ�գ�aһֱɾ�� 
	for(int j=0;j<=m;j++) f[0][j]=j; //��aΪ�գ�aһֱ���� 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{//�Ƚ�����������������ƥ��֮����иĵĲ���
			f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
			if(a[i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);//�������Ҫ���ˣ���ô��һ������ϼ�0
			else f[i][j]=min(f[i][j],f[i-1][j-1]+1); //�����Ҫ�ģ���ô����һ������ϼ�1
		} 
	cout<<f[n][m];
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


