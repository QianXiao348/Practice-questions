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
const int N = 2e5 + 10;
int n, m;
int p[N];
int f[N]; // ǰ1��i�����̨�����������ҵ�i�����̨ ��ȼ �ķ�������
int q[N], hh, tt;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    hh = 0, tt = -1;
    q[++tt] = 0;
    for (int i = 1; i <= n; i++)
    {
    	//����������i��࣬������i,ʹ��ǰ����Ϣ���Ը���f[i]���������ڳ����Ϊm
        while (hh <= tt && i - q[hh] > m)
            hh++;
        // ��Ϊi���ڻ��������У���Ҫ�û������ڵ����ݸ���f[i]����while�Ϸ�����
        f[i] = f[q[hh]] + p[i];
        while (hh <= tt && f[q[tt]] >= f[i])
            tt--;
        q[++tt] = i;
    }
    // �𰸿��ܴ����� n-1,n-2,...n-m+1�У�ö��һ������Сֵ����
    int res = INT_MAX;
    for (int i = n - m + 1; i <= n; i++)
        res = min(res, f[i]);
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
