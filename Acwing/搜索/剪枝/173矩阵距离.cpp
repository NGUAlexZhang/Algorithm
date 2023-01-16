#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
queue<pair<int,int>>q;
int ans[1200][1200];
void bfs(){
    while(q.size()){
        auto node=q.front();
        q.pop();
        auto x=node.first,y=node.second;
        for(int i=0;i<4;i++){
            auto nx=x+dx[i],ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(ans[nx][ny]==-1){
                ans[nx][ny]=ans[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    memset(ans,-1,sizeof(ans));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=1;j<=m;j++){
            char x=getchar();
            if(x=='1') ans[i][j]=0,q.push({i,j});
        }
    }
    bfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}