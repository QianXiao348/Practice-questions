#include <bits/stdc++.h> //��λdp 
using namespace std;
const int N = 32; // 2^{32}�㹻int����
int a[N], al;     // ��λ������õ�����
int f[N][N];      // ��һά���ڼ�λ�����ڶ�ά���ߵ���ǰ��λ���Ѿ�ȡ���˶��ٸ�
int n;            // ��ǰö�ٵ������ĸ���

/**
 u      :�Ӹߵ��ͣ������ǵڼ�λ��
 lead   :�Ƿ���ǰ����
 st     :����ǰ����Ѿ�����n�ĸ���
 op     :�Ƿ����Ͻ�
 ����ֵ :�ӵ�ǰ��λu�������ڵ�ǰlead,st,op��ǰ���£����Եõ����ٸ��������������
*/
int dfs(int u, int lead, int st, int op) {
    if (!u) return st;                              // �ݹ����,u==0ʱ��������λ������ϣ�al�Ǵ�1��ʼ������
    if (!lead && !op && ~f[u][st]) return f[u][st]; // ��ǰ��0 + �����Ͻ� + ���

    // uλ�ϵ����ֵ
    int up = op ? a[u] : 9; // ������Ͻ磬��op,�������ȫ��ȡ��

    int res = 0; // ��������������lead,st,op�ߵ�u�����λʱ�����տ��Ի�ȡ�����ٸ����أ�
    for (int i = 0; i <= up; i++) {
        int sum = st;
        // �� ǰ����ֹ���0���� ���� ��λ�÷�0
        // �� ��ǰ��λ��Ҫ���ҵ�����
        if ((!lead || i > 0) && i == n) sum++;
        // ���ԭ�������Ͻ磬���ڼ������Ͻ磬��ô���Ͻ����
        res += dfs(u - 1, lead && !i, sum, op && i == a[u]);
    }

    // ���仯
    if (!lead && !op) f[u][st] = res;
    return res;
}

int calc(int x) {
    al = 0;
    while (x) a[++al] = x % 10, x /= 10; // ��λ����,��λ����
    // al    :��alλ��ʼ
    // lead  :����ǰ��0
    // st    :ǰ�������������n�ĸ�����0��
    // op    :���Ͻ�
    return dfs(al, 1, 0, 1);
}

int main() {
    int l, r;
    while (cin >> l >> r, l || r) {  
        if (l > r) swap(l, r);        // ˭��˭С����һ
        for (n = 0; n <= 9; n++) {    // 0,1,2,3,...�������ж��ٸ�
            memset(f, -1, sizeof(f)); // ÿ����Ҫ��ʼ��dp����
            cout << calc(r) - calc(l - 1) << ' ';
        }
        cout << endl;
    }
    return 0;
}

