#include <bits/stdc++.h>
using namespace std;
long long a, b, n, m, dp[25][25], ma[25][25];
void pd(int x, int y) {
    ma[x][y] = 1;
    ma[x - 1][y - 2] = 1;
    ma[x - 2][y - 1] = 1;
    ma[x - 2][y + 1] = 1;
    ma[x - 1][y + 2] = 1;
    ma[x + 1][y - 2] = 1;
    ma[x + 2][y - 1] = 1;
    ma[x + 2][y + 1] = 1;
    ma[x + 1][y + 2] = 1;
}
int main(){
    cin>>n>>m>>a>>b;
    n++,m++,a++,b++;
    pd(a,b);
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++){
         if(i==1&&j==1) continue;
         if(ma[i][j]!=1) dp[i][j]=dp[i-1][j]+dp[i][j-1];
     }
    cout<<dp[n][m];
}
