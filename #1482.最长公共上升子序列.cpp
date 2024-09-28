#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int> PII;
const int dx[] = {-1,0,1,0,-1,1,1,-1};
const int dy[] = {0,1,0,-1,1,1,-1,-1}; 
const int mod = 1e9+7; 
const int N = 3010;
int n, m;
int a[N], b[N];
int f[N][N]; // ��̬�滮����
PII pre[N][N]; // ǰ�����飬���ڼ�¼·��
int c[N]; // ���ڴ洢���ս��������

int main() {
    PASE; // �Ż��������
    cin >> n; // �����һ�����еĳ���
    for (int i = 1; i <= n; i++) cin >> a[i]; // �����һ������
    cin >> m; // ����ڶ������еĳ���
    for (int i = 1; i <= m; i++) cin >> b[i]; // ����ڶ�������

    int ans = 0, ans_i = 0, ans_j = 0; // ���ڼ�¼������еĳ��ȼ������λ��
    for (int i = 1; i <= n; i++) {
        int mx = 0, mj = 0; // ��ʱ���������ڼ�¼��ǰ���Ž⼰��λ��
        for (int j = 1; j <= m; j++) {
            if (a[i] != b[j]) {
                // ���a[i]��b[j]����ȣ�ֱ�Ӽ̳�ǰ���״̬
                f[i][j] = f[i - 1][j];
                pre[i][j] = pre[i - 1][j];
            } else {
                // ���a[i]��b[j]��ȣ����µ�ǰ״̬
                f[i][j] = mx + 1;
                pre[i][j] = {i - 1, mj};
            }
            // ������ʱ����mx��mj
            if (b[j] < a[i] && mx < f[i - 1][j]) {
                mx = f[i - 1][j];
                mj = j;
            }
            // ����ȫ�����Ž�
            if (ans < f[i][j]) {
                ans = f[i][j];
                ans_i = i;
                ans_j = j;
            }
        }
    }

    cout << ans << endl; // ���������еĳ���
    int q = ans, i = ans_i, j = ans_j;
    while (q) {
        if (j) c[q--] = b[j]; // ����洢������
        auto &it = pre[i][j];
        i = it.fi, j = it.se;
    }
    for (int k = 1; k <= ans; k++) cout << c[k] << " "; // ����������
    return 0;
}

