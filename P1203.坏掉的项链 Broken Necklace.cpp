#include <bits/stdc++.h>
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
const int N = 1e3 + 10;
int n;
char s[N*2];
int lb[N], lr[N], rb[N], rr[N];
void solve()
{
    cin >> n;
    scanf("%s",s+1);
    for (int i = 1; i <= n; i++)
        s[i + n] = s[i];
    int res = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        if (s[i] == 'w')
        {
            lr[i] = lr[i - 1] + 1;
            lb[i] = lb[i - 1] + 1;
        }
        else if (s[i] == 'r')
            lr[i] = lr[i - 1] + 1;
        else if (s[i] == 'b')
            lb[i] = lb[i - 1] + 1;
    }
    for (int i = n * 2; i; i--)
    {
        if (s[i] == 'w')
        {
            rr[i] = rr[i + 1] + 1;
            rb[i] = rb[i + 1] + 1;
        }
        else if (s[i] == 'r')
            rr[i] = rr[i + 1] + 1;
        else if (s[i] == 'b')
            rb[i] = rb[i + 1] + 1;
    }
    for (int i = n; i; i--)
    {
        res = max(res, max(lr[i], lb[i]) + max(rr[i + 1], rb[i + 1]));
    }
    if (res > n)
        res = n;
    cout << res << endl;
}
int main()
{
    // freopen("in.txt", "rt", stdin);
    // freopen("out.txt", "wt", stdout);
    // PASE;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
