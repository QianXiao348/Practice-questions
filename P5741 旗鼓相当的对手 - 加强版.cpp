#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
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
struct student{
	string name;
	int a,b,c;
}a[1010];
int sum[1010];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].name>>a[i].a>>a[i].b>>a[i].c;
		sum[i]=a[i].a+a[i].b+a[i].c;
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(abs(sum[i]-sum[j])<=10){
				if(abs(a[i].a-a[j].a)<=5&&abs(a[i].b-a[j].b)<=5&&abs(a[i].c-a[j].c)<=5){
					cout<<a[i].name<<" "<<a[j].name<<endl;
				}
			}
		}
	}
}
int main(){
	PASE;
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}


