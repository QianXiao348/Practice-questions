#include <bits/stdc++.h> //��λdp 
using namespace std;

const int N = 15;
int a[N], al;
int f[N][N];

// st����ǰһ��λ�ϵ���ֵ
int dfs(int u, int st, bool lead, bool op) {
    if (u == 0) return 1;                           // �����ͷ�ˣ���ô��ǰ����������OK��
    if (!op && !lead && ~f[u][st]) return f[u][st]; // �����Ͻ磬��ǰ���㣬�����

    int ans = 0, up = op ? a[u] : 9;
    for (int i = 0; i <= up; i++) {
        if (abs(st - i) < 2) continue; // �����������֣����С��2
        if (lead && i == 0)            // ����ǰ����
            ans += dfs(u - 1, -2, true, op && i == a[u]);
        else // ������ǰ����
            ans += dfs(u - 1, i, false, op && i == a[u]);
    }
    // �����Ͻ磬��ǰ���㣬��¼�������
    if (!op && !lead) f[u][st] = ans;
    return ans;
}

int calc(int x) {
    al = 0;
    while (x) a[++al] = x % 10, x /= 10;
    return dfs(al, -2, 1, 1); //     ע��st�ĳ�ʼ��-2
}

signed main() {
    int l, r;
    cin >> l >> r;
    // windy�������ֱ����һ�����ʣ����Խ�memset�������
    memset(f, -1, sizeof f);

    cout << calc(r) - calc(l - 1) << endl;
    return 0;
}

