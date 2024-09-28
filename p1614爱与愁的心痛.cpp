#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int n, m;
int a[N];
int main()
{
	int sum = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <=n; i++)
	{
		scanf("%d", &a[i]);
		if (i <= m)
		sum += a[i];
	}
	int minx = sum;
	for (int i = m+1; i <= n; i++) {
		
		sum =sum+ a[i] - a[i-m];
		minx = min(sum,minx);
	}
	printf("%d", minx);
	return 0;
}
