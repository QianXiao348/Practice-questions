#include <bits/stdc++.h>//��λdp 

using namespace std;
typedef long long LL;

const int N = 20;
const LL mod = 1e9 + 7;

LL a[N];    // ���ڲ��ʮ����ÿһλ������
LL base[N]; // Ԥ�������10���ݴη�

struct Node {
    LL s0; // �����������ĸ��� ��(k,1)
    LL s1; // �������������ĺ� ��(k,A)
    LL s2; // ��������������ƽ���ĺͦ�(k,A^2)
} f[N][7][7];

/*
ά��1��u: ��λλ��
ά��2��sum: ǰ�������λ����λ��mod 7
ά��3��pre: ǰ�����ǰ׺�� mod 7
*/

// ö��λ��,ÿһλ�������ĺ�%7,�����%7,�ǲ������Ͻ�
Node dfs(int u, int sum, int pre, bool op) {
    // 1����u==0ʱ,��sum����7�ı���,����,pre����7�ı���ʱ,������ǺϷ���,������Ϊ1����
    // 2��Ϊʲô���ص�sum==0,pre==0�أ���Ϊ����Ҫ������һ��ȥ���,��仰����Ҫ��ϸ��Ậ��
    if (u == 0) return {(sum && pre), 0, 0};

    // ���仯
    if (!op && ~f[u][sum][pre].s0) return f[u][sum][pre];
    // �Ͻ�
    int up = op ? a[u] : 9;

    // ��״̬��u+sum+pre ��ͳ����Ϣ
    Node ans = {0, 0, 0};
    for (int i = 0; i <= up; i++) {
        if (i == 7) continue;
        Node ret = dfs(u - 1, (sum + i) % 7, (pre * 10 + i) % 7, op && (i == up));
        // �㼯����
        ans.s0 = (ans.s0 + ret.s0) % mod;
        // �㼯���ֺ�
        ans.s1 = (ans.s1 + ret.s0 * i % mod * base[u - 1] % mod + ret.s1) % mod;
        // �㼯����ƽ����
        ans.s2 = (ans.s2 + i * base[u - 1] % mod * i % mod * base[u - 1] % mod * ret.s0 % mod) % mod;
        ans.s2 = (ans.s2 + 2 * i % mod * base[u - 1] % mod * ret.s1 % mod + ret.s2) % mod;
    }
    // ��·
    if (!op) f[u][sum][pre] = ans;
    return ans;
}

LL calc(LL x) {
    int al = 0;
    while (x) a[++al] = x % 10, x /= 10;
    return dfs(al, 0, 0, true).s2;
}

int main() {
    // ��7�޹ص����������ֱ�������ԣ�����ȡģ��һ���̶�ֵ��������Ϊ�����뼸�ξͱ仯
    memset(f, -1, sizeof(f));

    // Ԥ�����10���ݴη�����Ϊ�漰��ȡģ��Ҫ�������⻹��Ԥ������
    base[0] = 1;
    for (int i = 1; i < N; i++) base[i] = base[i - 1] * 10 % mod;

    int T;
    cin >> T;
    LL l, r;
    while (T--) {
        cin >> l >> r;
        printf("%lld\n", (calc(r) - calc(l - 1) + mod) % mod); // ������ÿһ������Ҫע��ȡģ
    }
    return 0;
}

