#include<bits/stdc++.h>
using namespace std;
const int N = 510,M=5e4+10;
int h[N],e[M],ne[M],idx;
int match[N];
bool st[N];
int n1,n2,m;
void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
bool mate(int x){
	for(int i=h[x];i!=-1;i=ne[i]){
		int j=e[i];
		if(!st[j]){
			st[j]=true;
			if(match[j]==0||mate(match[j])){
				match[j]=x;
			    return true;
			}
		}
	}
	return false;
}
int main(){
    cin>>n1>>n2>>m;
    memset(h,-1,sizeof h);
    while(m--){
    	int a,b;
		cin>>a>>b;
		add(a,b),add(b,a); 
	}
	int res=0;
	for(int i=1;i<=n1;i++){
		memset(st,false,sizeof st);
		if(mate(i))
		 res++;
	}
	cout<<res;
	return 0;
}

