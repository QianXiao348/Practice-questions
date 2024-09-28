#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N]; 
int solver(int m,int n){
    vector<int>v;
    int res=0;
	for(int i=0;i<n;i++){
		auto it=find(v.begin(),v.end(),a[i]);
		if(it==v.end()){
			res++;
			v.push_back(a[i]);
		}
		else continue;
		if(v.size()>m){
			v.erase(v.begin());
		}
	}  
	return res;
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
    printf("%d",solver(m,n));
	return 0;
}

