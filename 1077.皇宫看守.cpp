#include <bits/stdc++.h>//树型dp 
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1510;
int n;
int h[N], e[N], ne[N], idx;
int w[N]; // 点的权值，不是边，不是边，不是边！
/*
状态表示：
（1）集合
f[u][0]：u号节点不放守卫，被父节点看守的方案
f[u][1]：u号节点不放守卫，被某个子节点看守的方案
f[u][2]：u号节点自己安排守卫看住的方案
（2）属性
花费最小值
*/
int f[N][3];
int in[N]; // 入度
// 邻接表
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u) {
    // 初始化
    f[u][0] = 0;    // 被父亲守护，对于u子树而言，代价为0
    f[u][1] = INF;  // 被某个子节点守护，但还没有评选中由哪个来看守更合适，预求最小先设最大
    f[u][2] = w[u]; // 被自己守护，对于u子树而言，代价为w[u]
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        // ① u不放守卫，被父节点守护，它的儿子们可以放守卫，也可以不放守卫，两者代价取min
        f[u][0] += min(f[j][1], f[j][2]);
        // ③ u放守卫，儿子可以指望父亲，可以自己放守卫，也可以指望某个孙子来守卫,三者代价取min
        f[u][2] += min({f[j][0], f[j][1], f[j][2]});
    }
    // ② u不放守卫，由某个好儿子守护
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        // Q:f[u][0]是什么意思？
        // 向上看第39行，本质上就是所有子节点j的最小花费值累加和，没有扣除掉孝顺儿子的花费值
        // 假设j是孝顺儿子，需要在其中扣除掉j的min(f[j][1],f[j][2])贡献,同时，
        // 它的代价跑不了，此时就不能取min了，而是实打实的f[j][2]
        f[u][1] = min(f[u][1], f[j][2] + f[u][0] - min(f[j][1], f[j][2]));
    }
}
int main() {
    memset(h, -1, sizeof h);       // 初始化
    cin >> n;                      // 节点数
    for (int i = 1; i <= n; i++) { // n个节点
        int x, m;                  // 节点号，代价,子节点数
        cin >> x >> w[x] >> m;
        while (m--) {
            int y;
            cin >> y;
            add(x, y); // 有向图
            in[y]++;   // 入度,用于找根
        }
    }
    // 找根
    int root = 1;
    while (in[root]) root++;
    // dfs
    dfs(root);
    // f[root][0]表示root不放守卫,被父节点看守，根节点是没有父节点的, 所以此状态是无效状态，不参与结果讨论
    // 最终最小代价值取min(f[root][1],f[root][2])
    printf("%d\n", min(f[root][1], f[root][2]));
    return 0;
}

