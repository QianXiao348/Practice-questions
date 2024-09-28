#include<bits/stdc++.h>
#include<unordered_map>
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

int main()
{
	FASE;
	int _;
	cin>>_;
	while(_--){
		int n,cnt=0;
		cin>>n;
		unordered_map<int,int>mp;
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			if(mp[t]) continue;
			else{
				cout<<t<<" ";
				mp[t]=1;
			}
		}
		cout<<endl;
	}
	return 0;
}

