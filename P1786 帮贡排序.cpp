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
const int N = 1e5+10;
int n;
struct Node{
	string name;
	string work;
	int con; 
	int leve;
	int id;
	int h;
}a[120];
bool cml(Node x,Node y){
	if(x.con==y.con) 
		return x.h<y.h;
	return x.con>y.con;
}
bool cml_2(Node x,Node y){
	if(x.id==y.id){
		if(x.leve==y.leve)
				return x.h<y.h;
		return x.leve>y.leve;	
	}
	return x.id>y.id;
}
void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].name>>a[i].work>>a[i].con>>a[i].leve;
		a[i].h=i;
	}
	sort(a+3,a+n,cml);
	for(int i=0;i<n;i++){
		if(i==0) a[i].work="BangZhu",a[i].id=7;
		else if(i==1||i==2) a[i].work="FuBangZhu",a[i].id=6;
		else if(i==3||i==4) a[i].work="HuFa",a[i].id=5;
		else if(i>=5&&i<=8) a[i].work="ZhangLao",a[i].id=4;
		else if(i>=9&&i<=15) a[i].work="TangZhu",a[i].id=3;
		else if(i>=16&&i<=40) a[i].work="JingYing",a[i].id=2;
		else a[i].work="BangZhong",a[i].id=1;
	}
	sort(a,a+n,cml_2);
	for(int i=0;i<n;i++) 
		cout<<a[i].name<<" "<<a[i].work<<" "<<a[i].leve<<endl;
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


