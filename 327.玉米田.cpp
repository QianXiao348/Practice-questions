#include <bits/stdc++.h> //״ѹdp
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MOD = 1e8;
const int N = 14, M = 1 << 12;
int n, m;
vector<int> state;   // ���кϷ���״̬��Ԥ����Ľ����
vector<int> head[M]; // ÿ��״̬���п���ת�Ƶ�������״̬
int f[N][M];         // ��ʾǰi���Ѿ����꣬���ҵ�i��״̬��k�����з�����
int g[N];
bool check(int x)
{
    return !(x & x >> 1);
}
int main()
{
    // freopen("in.txt", "rt", stdin);
    // freopen("out.txt", "wt", stdout);
    PASE;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int t;
            cin >> t;
            if (t == 0)
                g[i] |= 1 << (j - 1);
            // �ڶ�Ӧ�Ķ�����λ�ϵ�j-1λ��ʶΪ1������g[i]��ŵ���ʮ���ƣ����Խ����ӵĶ�����תΪʮ���Ƽ���g[i]
        }
    for (int i = 0; i < 1 << m; i++)//Ԥ��������״̬ 
        if (check(i))
            state.push_back(i);
    for (auto a : state)//ö�ٵ�i��״̬ 
        for (auto b : state) //ö�ٵ�i-1��״̬ 
        {
            if ((a & b) == 0)
                head[a].push_back(b);
        }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int a : state)
        {
            if (g[i] & a)// �����ǰö�ٳ���a˵ĳ��λ����Ҫ��ֲ���ף���g[i]��¼�Ĵ�λ�ò�������ô�Ͳ����ڴ�λ�ø���
                continue;
            for (int b : head[a])
            {
                f[i][a] = (f[i][a] + f[i - 1][b]) % MOD;
            }
        }
    int res = 0;
    for (int a : state)
        res = (res + f[n][a]) % MOD;
    cout << res << endl;
    return 0;
}
