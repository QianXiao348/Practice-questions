#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int x[N],y[N],n;
void solve() {
    cin>>n;
   for(int i=0;i<n;i++){
   	cin>>x[i];
   } 
    for(int i=0;i<n;i++){
   	cin>>y[i];
   } 
   sort(x,x+n);
   sort(y,y+n);
   for(int i=0;i<n;i++){
   	 if(x[i]>y[i]){
   	  cout<<"NE"<<endl;
   	  return;
    }
   }
   cout<<"DA"<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
