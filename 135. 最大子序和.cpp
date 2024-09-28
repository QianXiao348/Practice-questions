#include <bits/stdc++.h> //���������Ż�dp
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 10000007;
const double eps = 1e-8;
const int N = 1e6 + 10;
int n, k;
int a[N], s[N];
int q[N], hh, tt;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    hh = 0, tt = -1;
    int res = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        while (hh <= tt && i - k > q[hh]) //���ڴ��ڵ��ӵ� 
            hh++;
        res = max(res, s[i] - s[q[hh]]);
        while (hh <= tt && s[q[tt]] >= s[i])  //��ǰ�ĺͱȶ�β�ĺͻ�С����С����; 
            tt--;
        q[++tt] = i;//����� 
    }
    cout << res << endl;
}
int main()
{
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
    PASE;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
