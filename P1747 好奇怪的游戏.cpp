#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int>pll;
int x1,y1,x2,y2;
int dx[12] = { -2,-2,-2,-2,-1,1,2,2,2,2,1,-1 };
int dy[12] = { -2,-1,1,2,2,2,2,1,-1,-2,-2,-2 };
int dist[25][25];
queue<pll>q;
int bfs(int sx, int sy) {
	memset(dist, -1, sizeof dist);
	q.push({ sx,sy });
	dist[sx][sy] = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 12; i++) {
			int a = t.x + dx[i], b = t.y + dy[i];
			if (a < 1 || a>20 || b < 1 || b>20) continue;
			if (dist[a][b] > 0) continue;
			dist[a][b] = dist[t.x][t.y] + 1;
			q.push({ a,b });
			if (a == 1 && b == 1) {
				return dist[a][b];
			}

		}
	}
}
int main() {
	cin >> x1 >> y1 >> x2 >> y2;
	cout << bfs(x1, y1) << endl;
	while (!q.empty()){//每次搜索完后需要把队列清空  因为到达目标点时队列可能不为空 影响下个物体搜寻 
		q.pop();
	}
	cout << bfs(x2, y2) << endl;
	return 0;
}

