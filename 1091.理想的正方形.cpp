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
const int N = 1010;
int n, m, k;
int w[N][N];
int f[N];
int q[N], hh, tt;
void get_min(int a[], int b[], int col)
{
    int hh = 0, tt = -1; // ��ǰ׺����صģ��Ż����ڱ��������ǰ׺��û��ϵ�����ü����ڱ���
    for (int i = 1; i <= col; i++)
    {
        //�����ӣ�����i=5,k=3,�򴰿ڷ�Χ��[3,4,5],Ҳ������Զ�Ķ�ͷԪ���±���i-k+1,�ٱ���С�Ͳ�����
        while (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;
        //�˴���Ҫ����i������������ӵ����к���м���
        b[i] = a[q[hh]];
    }
}
void get_max(int a[], int b[], int col)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= col; i++)
    {
        while (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    /*����I������ÿһ�У������Сֵ�����ֵ������ת�����ֱ��¼��row_min��row_max���������С�
    ���������飬ֻ��һ���м��״̬����Ϊ�˸�����II�����ż���k����Χ�ڵļ���Сֵ���ṩ���ʯ��
    */
    int row_max[N][N];
    int row_min[N][N];
    for (int i = 1; i <= n; i++)
    {
        get_min(w[i], row_min[i], m);
        get_max(w[i], row_max[i], m);
    }
    int t[N], a[N], b[N];
    /*
    ����II:����������伫ֵ�����½ǹ鲢
      (1)������row_min����ÿһ�н�����ת�У�����Ϊt
      (2)������get_min ��t�����ٴδ洢Ϊa����
      (3)����a���飬��������ң��Ϲ��µģ��߳�Ϊk�ľ����е���Сֵ��

      (4)������row_max����ÿһ�н�����ת�У�����Ϊt
      (5)������get_max ��t�����ٴδ洢Ϊb����
      (6)����b���飬��������ң��Ϲ��µģ��߳�Ϊk�ľ����е����ֵ��
    */
    int res = INT_MAX;
    for (int j = k; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
            t[i] = row_min[i][j];
        get_min(t, a, n);
        for (int i = 1; i <= n; i++)
            t[i] = row_max[i][j];
        get_max(t, b, n);
        for (int i = k; i <= n; i++)
            res = min(res, b[i] - a[i]);
    }
    cout << res << endl;
}
int main()
{
    // freopen("in.txt", "rt", stdin);
    // freopen("out.txt", "wt", stdout);
    PASE;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
