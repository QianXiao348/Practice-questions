#include <bits/stdc++.h>//����dp--�·�� 
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 1e8;
const double eps = 1e-8;
const int N = 1e4 + 10, M = N * 2;
int n;
int w[M], h[N], e[M], ne[M], idx;
int ans;
int d1[N],d2[N];//� �γ����� 
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
//����������ȸ��γ����� 
void dfs(int u, int fa) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue; // v����ʹ���
        // ��v����,��ɺ�v������ÿ���ڵ��mx1[v],d2[v]���Ѿ�׼���ã�u�ڵ����ֱ������
        dfs(v, u);

        // w[i]:u->v��·������,mx1[u]:�·��,d2[u]:�γ�·��
        int x = d1[v] + w[i];
        if (d1[u] <= x)                 // v������������u�����ֵ
            d2[u] = d1[u], d1[u] = x; // �·ת��
        else if (d2[u] < x)
            d2[u] = x; // �γ�·ת��
    }
    // ���½��
    ans = max(ans, d1[u] + d2[u]);
}
void solve()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1);
    cout << ans << endl;
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
