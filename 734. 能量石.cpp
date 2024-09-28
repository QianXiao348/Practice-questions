#include<bits/stdc++.h>//01背包+贪心 
using namespace std;
const int N =1e4+10;
int n;
int f[N];
int idx;
struct Node{
    int s,e,l;
}a[N];
bool cml(Node &x,Node &y){ //贪心微扰法得出顺序结论 
    return x.s*y.l<=y.s*x.l;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i].s>>a[i].e>>a[i].l;
            sum+=a[i].s;
        }
        sort(a+1,a+1+n,cml);
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++){
            int s=a[i].s,e=a[i].e,l=a[i].l;
            for(int j=sum;j>=s;j--){
                f[j]=max(f[j],f[j-s]+max(0,e-(j-s)*l));
            }
        }
        printf("Case #%d: %d\n",++idx,*max_element(f,f+sum+1));
    }
    return 0;
}
