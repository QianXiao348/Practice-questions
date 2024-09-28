 #include<bits/stdc++.h>//优化后双向队列 
using namespace std;
#define x first
#define y second
int n, x2, y2, x3, y3;
char ch[1010][1010];
int dist[1010][1010];
int vis[1010][1010]; 
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
typedef pair<int, int> pll;
queue<pll>q;
int  bfs(int x1, int y1) {
	memset(dist, -1, sizeof dist);
	memset(vis,-1,sizeof vis);
	q.push({x1,y1});
	q.push({x3,y3});
	dist[x1][y1] = 0;
	dist[x3][y3] = 0;
	vis[x1][y1]=1;
	vis[x3][y3]=2;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int a = t.x + dx[i],b = t.y+ dy[i];
			if (a <1 || a > n || b <1 || b > n) continue;
			if (ch[a][b] != '0') continue;
			if(vis[a][b]+vis[t.x][t.y]==3){
				return dist[a][b]+dist[t.x][t.y]+1;
			}
			if (dist[a][b] >=0) continue;
		     q.push({ a,b });
			dist[a][b] = dist[t.x][t.y] + 1;
			if(vis[a][b]==-1){
				vis[a][b]=vis[t.x][t.y];
			} 
			
		}
	}
	return -1;		
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) 
			scanf("%s",ch[i]+1);//从0位置偏移到1的点 
	scanf("%d%d%d%d",&x2,&y2,&x3,&y3);
	printf("%d\n",bfs(x2, y2));
	return 0;
}

