#include<bits/stdc++.h>//bfs 
using namespace std;
#define fi first
#define se second
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
const int N = 110;
int g[N][N];
int n,m;
int dist[N][N];
bool st[N][N];
void bfs(){
    queue<PII>q;
    dist[1][1]=0;
    st[1][1]=1;
    q.push({1,1});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=t.fi+dx[i],b=t.se+dy[i];
            if(a<1||b<1||a>n||b>m) continue;
            if(st[a][b]) continue;
            if(g[a][b]==0){
                q.push({a,b});
                dist[a][b]=dist[t.fi][t.se]+1;
                st[a][b]=1;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];
    bfs();
    cout<<dist[n][m];
    return 0;
}
