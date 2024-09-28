#include <bits/stdc++.h>//����dp 
using namespace std;
typedef long long LL;
const int N = 60, M = 35;
int n;
LL w[N];
LL f[N][N][M];//f[i][j][k] ��ʾ�ӵ� i ���� j ��һ�ε����˻���,ĳ���߾������ĵ� k λ��
// �ж�a>b
bool cmp(LL a[], LL b[])
{
	for (int i = M - 1; i >= 0; i--) // ֱ�ӴӸ�λ���бȽ�,���ĳһλa[i]>b[i]����˵��a��b�������
	{
		if (a[i] > b[i])
			return true;
		if (a[i] < b[i])
			return false;
	}
	return false;
}
// ֱ�Ӵ�0λ(��λ)�ӣ�һֱ�ӵ����λM-1λ
void add(LL a[], LL b[])
{
	LL c[M] = {0}, t = 0;
	for (int i = 0; i < M; i++)
	{
		t += a[i] + b[i];
		c[i] = t % 10;
		t /= 10;
	}
	memcpy(a, c, sizeof c);
}
// ��0λ(��λ)��ʼ�ˣ�һֱ�˵����λM-1λ
void mul(LL a[], LL b)
{
	LL c[M] = {0}, t = 0;
	for (int i = 0; i < M; i++)
	{
		t += a[i] * b;
		c[i] = t % 10;
		t /= 10;
	}
	memcpy(a, c, sizeof c);
}
// ��ӡ�߾��Ƚ������
void print(LL a[])
{
	int k = M - 1;
	while (k && !a[k])
		k--; // ���֮ǰҪ�����е�ǰ��0��ȥ��
	for (int i = k; i >= 0; i--)
		cout << a[i];
	cout << endl;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int len = 3; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			f[i][j][M - 1] = 1; // ��Ϊ�߾��������Ǹ�λ���ң���λ�����������õ������λΪ1
			for (int k = i + 1; k < j; k++)
			{
				LL t[M] = {0}; // ��ʱ�߾�������
				t[0] = 1;	   // �˷������籾ԭ
				mul(t, w[i]);
				mul(t, w[k]);
				mul(t, w[j]);
				add(t, f[i][k]);
				add(t, f[k][j]);
				if (cmp(f[i][j], t))
					memcpy(f[i][j], t, sizeof t);
			}
		}
	}
	print(f[1][n]);
	return 0;
}
