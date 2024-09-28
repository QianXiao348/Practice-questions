#include<bits/stdc++.h>
using namespace std;
#define FASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int mod = 1e9+7;
const double eps = 1e-6;
const double PI = 3.1415926;
const int N = 10;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n;
double x_1,y_1,x_2,y_2;
double x[N],y[N],r[N];
double max_res;
bool st[N];
double calc(int u){
	double t1=min(abs(x[u]-x_1),abs(x[u]-x_2));
	double t2=min(abs(y[u]-y_1),abs(y[u]-y_2));
	double res=min(t1,t2);
	for(int j=1;j<=n;j++){
		if(u!=j&&st[j]){
			double d=sqrt(pow(abs(x[u]-x[j]),2)+pow(abs(y[u]-y[j]),2));
			res=min(res,max(d-r[j],0.0));
		}
	}
	return res;
}
void dfs(int u,double sum){
	if(u>n){
		max_res=max(max_res,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!st[i]){
			r[i]=calc(i);
			st[i]=true;
			dfs(u+1,sum+PI*r[i]*r[i]);
			st[i]=false;
		}
	}
}
int main()
{
	FASE;
	double ss;
	cin>>n;
	cin>>x_1>>y_1>>x_2>>y_2;
	ss=abs(x_1-x_2)*abs(y_1-y_2);
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	dfs(1,0);
	cout<<(int)(ss-max_res+0.5)<<endl;
	return 0;
}

