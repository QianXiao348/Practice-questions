#include <bits/stdc++.h> //���������Ż�dp 
using namespace std;
const int N = 100010;
typedef long long LL;
int q[N];
LL s[N], f[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];

    // ���ڻ���������i����ߣ���Ҫ����ǰ׺�͵�s[l-1],��1��û��ǰ�򣬲���������Ĵ����߼��������һ���ڱ�
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) {
        // ��1���������m���ϼһ��ǣ������ǲ���ʵ����ǿ��һ��ȥ��
        while (hh <= tt && i - q[hh] > m) hh++;

        // ��Ϊ����������i ��࣬��ʹ���ټ���
        f[i] = max(f[i - 1], f[max(0, q[hh] - 1)] + s[i] - s[q[hh]]);

        // ��2�����������ᣬ���ң���������ʵ�����ϼһ���ȥ��
        while (hh <= tt && f[i - 1] - s[i] >= f[max(0, q[tt] - 1)] - s[q[tt]]) tt--;

        // 3��i�����
        q[++tt] = i;
    }
    // ������
    cout << f[n] << endl;
    return 0;
}

