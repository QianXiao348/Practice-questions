#include<bits/stdc++.h>
using namespace std;
const int N = 125;
int n;
int a[N][N],s[N][N];
int main(){
    cin>>n;
    int res=INT_MIN;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++){
	   cin>>a[i][j];
	   s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
    }
    for(int x1=1;x1<=n;x1++){
    	for(int y1=1;y1<=n;y1++){
    		for(int x2=x1;x2<=n;x2++){
    			for(int y2=y1;y2<=n;y2++){
    			  	int tres=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
    			  	res=max(res,tres);
				}
			}
		}
	}
	cout<<res<<endl;
	return 0;
}

