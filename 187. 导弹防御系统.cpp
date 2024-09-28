#include <bits/stdc++.h>// 贪心+爆搜
using namespace std;
const int N = 55;
const int INF = 0x3f3f3f3f;
int n;
int a[N];
int up[N], down[N];
int res;
/*
 功能：暴搜所有可能，配合剪枝，找出最少的拦截系统数量
 u:  第几个导弹
 ul: 上升拦截系统的数量，配合up  数组使用
 dl: 下降拦截系统的数量，配合down数组使用
 */
void dfs(int u, int ul, int dl) {
    if (ul + dl >= res) return; // 伟大的剪枝，不剪枝会TLE~,中途发现已经大于等于res的情况，就返回
    if (u == n) {               // 走完全程,收集答案
        res = ul + dl;          // 因为上面的剪枝，把ul+dl>=res的全干掉了，能到这里的，都是<res的，都可以用来更新答案
        return;
    }
    // 放入上升序列
    int k = 0;
    // 如果把当前导弹使用上升序列的拦截系统进行拦截，那个选择哪个系统呢？
    for (k = 0; k < ul; k++)
        if (up[k] <= a[u]) break; // up[0],up[1],up[2],... 这样套拦截系统，其数值来讲，是递减的，因为是因为不能再拦截高度更低的才创建了一套新的拦截系统
    // 找出放到哪个拦截系统上去，结果为k
    int t = up[k]; // 尝试在第k套系统进行拦截第u个导弹,那么，第u个导弹的高度就是第k套系统的新高度
    up[k] = a[u];  // 问题是，我们也不一定非得让第u个导弹使用上升序列拦截系统，也可能使用下降序列拦截系统，所以需要记录当前值，回溯后，尝试下降序列拦截
    if (k < ul)                 // 如果当前这些套拦截系统中可以找到某一套进行拦截
        dfs(u + 1, ul, dl);     // 接到了某个队伍后面去了，修改队伍的最后最大值即可，队伍数量没有长大
    else                        // 如果当前这些套拦截系统中无法找到某一套进行拦截
        dfs(u + 1, ul + 1, dl); // 没有找到任何一个符合最后一个高度小于a[u]的队伍，只能多开一队，up数组长度长大1
    up[k] = t; // 回溯
    // ----------------------------------------------------------------------

    // 放入下降序列
    k = 0;
    for (k = 0; k < dl; k++)
        if (down[k] >= a[u]) break;
    t = down[k]; // 保留现场
    down[k] = a[u];
    if (k < dl)
        dfs(u + 1, ul, dl);
    else
        dfs(u + 1, ul, dl + 1);
    down[k] = t; // 回溯
}
int main() {
    while (cin >> n, n) { // 多套数据，输入n=0时停止
        for (int i = 0; i < n; i++) cin >> a[i];
        res = INF;    // 防御系统的最少数量
        dfs(0, 0, 0); // 开始深搜，更新res的值
        printf("%d\n", res);
    }
    return 0;
}

