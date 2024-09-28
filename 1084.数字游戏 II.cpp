#include <bits/stdc++.h> //��λdp 

using namespace std;

const int N = 32;
const int M = 100; // n<=100,���� mod n �Ľ�������99

int mod;
int a[N], al;
int f[N][M];

int dfs(int u, int st, bool op) {
    if (u == 0) return st % mod == 0; // ��λ���ֺ� %n == 0����һ����

    if (!op && ~f[u][st]) return f[u][st];

    int ans = 0, up = op ? a[u] : 9;
    for (int i = 0; i <= up; i++)
        ans += dfs(u - 1, (st + i) % mod, op && i == a[u]);

    if (!op) f[u][st] = ans;
    return ans;
}

int calc(int x) {
    // ���ʣ�Ϊʲô���ⲻ�ܽ�memset�����������أ�����Ϊȡģ��ɵ���
    // ���ǵģ���Ϊn��ÿ��ȫ�������,�������Ȥ�������ټ�һά��ά��n
    memset(f, -1, sizeof f);
    al = 0;
    while (x) a[++al] = x % 10, x /= 10;
    // ĳ����������һ��ȡģ�����������ֱ��������λ����֮�� mod N Ϊ 0��
    // ǰ0λ���ֺ�Ϊ0,st = 0
    return dfs(al, 0, true);
}

int main() {
    int l, r;
    while (cin >> l >> r >> mod)
        printf("%d\n", calc(r) - calc(l - 1));
    return 0;
}
