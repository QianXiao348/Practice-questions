#include <bits/stdc++.h> //状压dp
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
vector<int> state;   // 所有合法的状态（预处理的结果）
vector<int> head[M]; // 每个状态所有可以转移到的其他状态
int f[N][M];         // 表示前i行已经摆完，并且第i行状态是k的所有方案。
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
            // 在对应的二进制位上第j-1位标识为1，这里g[i]存放的是十进制，所以将增加的二进制转为十进制加入g[i]
        }
    for (int i = 0; i < 1 << m; i++)//预处理所有状态 
        if (check(i))
            state.push_back(i);
    for (auto a : state)//枚举第i行状态 
        for (auto b : state) //枚举第i-1行状态 
        {
            if ((a & b) == 0)
                head[a].push_back(b);
        }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int a : state)
        {
            if (g[i] & a)// 如果当前枚举出的a说某个位置需要种植玉米，而g[i]记录的此位置不育，那么就不能在此位置耕种
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
