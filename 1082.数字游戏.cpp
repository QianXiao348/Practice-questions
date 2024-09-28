#include <bits/stdc++.h>//��λdp 
using namespace std;
const int N = 32;
int l, r;
int a[N], al;
int f[N][N];
/**
 *
 * @param u ��ǰ����λ
 * @param st  ǰһλ��д����ʲô
 * @param op  �ǲ������Ͻ�
 * @return    �ڵ�ǰ����£����������������ж��ٸ�
 */
int dfs(int u, int st, bool op) {
    if (u == 0) return 1; // ���������������������ţ�˵��ǰ��Ķ���������������һ�������++
    if (!op && ~f[u][st]) return f[u][st];
    int ans = 0, up = op ? a[u] : 9;
    for (int i = st; i <= up; i++) // ע����ʼ��,i >= st
        ans += dfs(u - 1, i, op && i == a[u]);

    if (!op) f[u][st] = ans;
    return ans;
}

int calc(int x) {
    al = 0;
    while (x) a[++al] = x % 10, x /= 10;
    return dfs(al, 0, true);
}

int main() {
    memset(f, -1, sizeof f);
    while (~scanf("%d%d", &l, &r))
        printf("%d\n", calc(r) - calc(l - 1));
    return 0;
}
