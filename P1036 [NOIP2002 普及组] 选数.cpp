#include<bits/stdc++.h>
using namespace std;
const int N= 30;
int n,k,ans;
int arr[N],q[N];
bool prime(int y)
{
    if(y<2) return false;
    for(int i=2;i<=sqrt(y);i++){
     if(y%i==0)
      return false;
    }
    return true;
}
void dfs(int x,int  start)
{
	if(x-1+n-start+1<k) return;//¼ôÖ¦ 
    if(x>k){
        int sum=0;
        for(int i=1;i<=k;i++){
            sum+=arr[i];
        }
        if(prime(sum))
         ans++;
        return ;
    }
    for(int i=start;i<=n;i++){
        arr[x]=q[i];
        dfs(x+1,i+1);
        arr[x]=0;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
     scanf("%d",&q[i]);
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}
