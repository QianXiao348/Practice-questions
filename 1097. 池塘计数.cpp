#include<bits/stdc++.h>//Flood Fill
using namespace std;
const int N = 1010;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
char g[N][N];
int n,m;
int res;
void bfs(int x,int y){
    queue<PII>q;
    q.push({x,y});
    g[x][y]='.';
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<1||b<1||a>n||b>m) continue;
            if(g[a][b]=='W'){
                q.push({a,b});
                g[a][b]='.';
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(g[i][j]=='W'){
                res++;
                bfs(i,j);
            }
        }
    cout<<res<<endl;
    return 0;
}
