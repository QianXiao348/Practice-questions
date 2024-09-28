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
const int N = 5e4+10;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
map<string,string>fa;
string find(string x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	FASE;
	string s,s1;
	char ch;
	while(1){
		cin>>ch;	
		if(ch=='$') break;
		cin>>s;
		if(ch=='#'){
			s1=s;
			if(fa[s]=="") fa[s]=s;
		}
		else if(ch=='+'){
			fa[s]=s1;
		}
		else if(ch=='?'){
			cout<<s<<" "<<find(s)<<endl;
		}
	}
	return 0;
}

