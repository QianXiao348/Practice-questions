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
const int N = 10;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n;
string A,B;
unordered_map<string,int>da,db;
string a[N],b[N];
int bfs(){
	if(A==B) return 0;
	queue<string>qa,qb;
	qa.push(A);
	qb.push(B);
	da[A]=db[B]=0;
	while(qa.size()&&qb.size()){
		if(qa.size()<=qb.size()){
			int t=qa.size();
			while(t--){
				auto now=qa.front();
				qa.pop();
				if(da[now]>10) return -1;
				for(int i=0;i<now.size();i++){
					for(int j=1;j<=n;j++){
						if(now.substr(i,a[j].size())==a[j]){
							auto s=now.substr(0,i)+b[j]+now.substr(i+a[j].size());
							if(da.count(s)) continue;
							da[s]=da[now]+1;
							if(db.count(s)) return da[s]+db[s];
							qa.push(s);
						}
					}
				}
			}
		}
		else{
			int t=qb.size();
			while(t--){
				auto now=qb.front();
				qb.pop();
				if(db[now]>10) return -1;
				for(int i=0;i<now.size();i++){
					for(int j=1;j<=n;j++){
						if(now.substr(i,b[j].size())==b[j]){
							auto s=now.substr(0,i)+a[j]+now.substr(i+b[j].size());
							if(db.count(s)) continue;
							db[s]=db[now]+1;
							if(da.count(s)) return da[s]+db[s];
							qb.push(s);
						}
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
	FASE;
	cin>>A>>B;
	n=1;
	while(cin>>a[n]>>b[n]){
		n++;
	}
	n--;
	int t=bfs();
	if(t==-1)
		cout<<"NO ANSWER!"<<endl;
	else cout<<t<<endl;
	return 0;
}

