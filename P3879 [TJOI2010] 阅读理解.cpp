#include<bits/stdc++.h>
using namespace std;
#define FASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const double PI = 3.1415926;
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 1e5+10;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
map<string,set<int>>mp;
int main()
{
	FASE;
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			string s;
			cin>>s;
			mp[s].insert(i);
		}
	}
	int m;
	cin>>m;
	while(m--){
		string s;
		cin>>s;
		if(mp.count(s)){
			for(auto it:mp[s]){
				cout<<it<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

