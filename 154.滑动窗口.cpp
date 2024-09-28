#include <bits/stdc++.h>

using namespace std;
const int N = 1000010;
int n;
int k;
int a[N];
int q[N], hh, tt;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 初始化队列
    hh = 0, tt = -1;
    for (int i = 1; i <= n; i++) {
        // Q1:队列里面放的是什么？
        // A1:是数组下标，是编号，不是值，需要值时，可以通过a[q[hh]]去取值

        // Q2:队列的存入形态是什么样的？
        // A2: hh....tt,hh在左，tt在右

        // Q3:什么样的需要出队列？
        // A3: （1）距离当前位置超过窗口范围
        //      (2) 在窗口范围内,但对后续没有可能发挥作用：区间内的人员，有比你更年轻、更漂亮的，怎么选美也选不到你
        while (hh <= tt && i + 1 - k > q[hh]) hh++; // q[hh]:窗口的左起点,hh++:减小窗口长度
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;  // tt--:减小窗口长度
        // q[],hh,tt 三者组成了一个模拟的队列数据结构，对外提供：查询队列中最小值位置的服务q[hh]，对内三者互相协作
        //  换言之：q[hh]是对外的，hh,tt是数据结构内部概念，不能混淆
        q[++tt] = i;
        // 只有在区间长度够长的情况下，才能输出区间最小值
        if (i >= k) printf("%d ", a[q[hh]]);
    }

    puts("");

    hh = 0, tt = -1;
    for (int i = 1; i <= n; i++) {
        while (hh <= tt && i + 1 - k > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if (i >= k) printf("%d ", a[q[hh]]);
    }
    return 0;
}

