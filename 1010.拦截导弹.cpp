#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1e5+10;
void solve(){
	 while (cin >> a[n]) n++;
    for (int i = 0; i < n; i++) {
        f[i] = 1, g[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] <= a[j])
                f[i] = max(f[i], f[j] + 1);
            else
                g[i] = max(g[i], g[j] + 1); 
        }
        fl = max(fl, f[i]), gl = max(gl, g[i]);
    }
    cout<<fl<<endl<<gl;
}
int main(){
	PASE;
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}


