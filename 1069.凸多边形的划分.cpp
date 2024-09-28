#include <bits/stdc++.h>//区间dp 
using namespace std;
typedef long long LL;
const int N = 60, M = 35;
int n;
LL w[N];
LL f[N][N][M];//f[i][j][k] 表示从第 i 到第 j 的一段的最大乘积和,某个高精度数的第 k 位。
// 判断a>b
bool cmp(LL a[], LL b[])
{
	for (int i = M - 1; i >= 0; i--) // 直接从高位进行比较,如果某一位a[i]>b[i]，则说明a比b这个数大
	{
		if (a[i] > b[i])
			return true;
		if (a[i] < b[i])
			return false;
	}
	return false;
}
// 直接从0位(个位)加，一直加到最高位M-1位
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
// 从0位(个位)开始乘，一直乘到最高位M-1位
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
// 打印高精度结果数组
void print(LL a[])
{
	int k = M - 1;
	while (k && !a[k])
		k--; // 输出之前要将所有的前导0都去掉
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
			f[i][j][M - 1] = 1; // 因为高精度数组是高位在右，低位在左，这里设置的是最高位为1
			for (int k = i + 1; k < j; k++)
			{
				LL t[M] = {0}; // 临时高精度数组
				t[0] = 1;	   // 乘法的世界本原
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
