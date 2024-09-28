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
void solve(){
	string s[5];
	map<char,int>mp;
	for(int i=0;i<4;i++)
		getline(cin,s[i]);
	int max_s=-1;
    for(int i=0;i<4;i++){
        for(int j=0;j<s[i].size();j++){
			if(s[i][j]>='A'&&s[i][j]<='Z'){
				mp[s[i][j]]++;
            	max_s=max(max_s,mp[s[i][j]]);
			} 
		}
   }
   for(int i=max_s;i>0;i--){
   		for(char j='A';j<='Z';j++){
   			if(mp[j]>=i) cout<<"* ";
   			else cout<<"  ";	
		}
		cout<<endl;
   }
   for(char i='A';i<='Z';i++) cout<<i<<" ";
}
int main(){
	PASE;
	int _;
	_=1;
	while(_--){
		solve();
	}
	return 0;
}


