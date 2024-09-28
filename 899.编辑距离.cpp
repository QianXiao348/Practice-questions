#include<bits/stdc++.h>//lcs
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 15;
const int M = 1010;
int n, m;
int f[N][N];
char str[M][N];
int cal(char a[], char b[]) {
    int la = strlen(a + 1), lb = strlen(b + 1);
    for (int i = 0; i <= lb; i++) f[0][i] = i;
    for (int i = 0; i <= la; i++) f[i][0] = i;
    for (int i = 1; i <= la; i++)
        for (int j = 1; j <= lb; j++) {
            // 增加和删除
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            // 修改
            if (a[i] == b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else // 相等
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    return f[la][lb];
}
void solve(){
	cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> (str[i] + 1); // 二维数组，躲开第一列
    while (m--) {
        char s[N];
        int limit;
        cin >> (s + 1) >> limit;
        int res = 0;
        for (int i = 0; i < n; i++)
            if (cal(str[i], s) <= limit) res++;
        cout << res << endl;
    }
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


