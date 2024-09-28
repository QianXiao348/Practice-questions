#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m,c;
int a[N][N],s[N][N];
int main(){
    cin>>n>>m>>c;
    int res=INT_MIN;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++){
      cin>>a[i][j];
      s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    }
    int i1,j1;
    for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
     	int x2=i+c-1,y2=j+c-1;
     	if(x2>n||y2>m) continue;
     	int tres=s[x2][y2]-s[i-1][y2]-s[x2][j-1]+s[i-1][j-1];
     	if(res<tres){
     		res=tres;
     		i1=i,j1=j;
		 }
	 }
   }
	cout<<i1<<" "<<j1;
	return 0;
}

