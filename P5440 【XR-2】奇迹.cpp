#include<bits/stdc++.h>
using namespace std;
#define FASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 1e8;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

LL primes[N+1],idx;
bool st[N+1];
LL ans;
vector<LL>v;
void get_primes(int n){
	st[1]=true;
	for(int i=2;i<=n;i++){
		if(!st[i]) primes[idx++]=i;
		for(int j=0;primes[j]<=n/i;j++){
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
int pd_leap(int x){
	if(x%400==0) return 1;
	if(x%100!=0&&x%4==0) return 1;
	return 0;
}
bool check(LL a){
	int y=a/10000;
	int m=(a%10000)/100;
	int d=a%100;
	if(d==0) return false;
	if(m==4||m==6||m==9||m==11) 
		return d<=30;
	else if(m==2)
		return d<=28+pd_leap(y);
	else return d<=31;
}
void dfs(string &s,int u){
	if(u==4){
		int y=0;
		for(int i=0;i<4;i++)
			y=y*10+v[i];
		if(!y) return;	
	}
	if(u==6){
		int m=v[4]*10+v[5];
		if(m==0||m>12) return;
	}
	if(u==8){
		int a=0;
		for(int i=0;i<8;i++)
			a=a*10+v[i];
		if(!st[a] && !st[a%10000] && !st[a%100] && check(a))
			ans++;
		return;
	}
	if(isdigit(s[u])){
		v.push_back(s[u]-'0');
		dfs(s,u+1);
		v.pop_back();
	}
	else{
		for(int i=0;i<=9;i++){
			v.push_back(i);
			dfs(s,u+1);
			v.pop_back();
		}
	}
}
int main()
{
	FASE;
	get_primes(N-1);
	int _;
	cin>>_;
	while(_--){
		string s;
		cin>>s;
		ans=0;
		dfs(s,0);
		cout<<ans<<endl;
	}
	return 0;
}

