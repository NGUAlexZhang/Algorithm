#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[1500][1500],dx[]={0,0,-1,1},dy[]={-1,1,0,0},st[1500][1500];
bool vis[1500][1500];
const int mod=1e9+7;
ll dp[1500][1500];
bool check_end(int x,int y){
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(a[nx][ny]==a[x][y]+1) return false;
    }
    return true;
}
bool check_start(int x,int y){
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(a[nx][ny]+1==a[x][y]) return false;
    }
    return true;
}
void dfs1(int x,int y,int step){
    if(step==4){
        st[x][y]++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(a[nx][ny]!=a[x][y]+1) continue;
        dfs1(nx,ny,step+1);
    }
}
ll dfs2(int x,int y){
    if(vis[x][y]) return dp[x][y];    
    dp[x][y]=st[x][y],vis[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(a[nx][ny]+1!=a[x][y]) continue;
        dp[x][y]+=dfs2(nx,ny);
        dp[x][y]%=mod;
    }
    return dp[x][y];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(check_start(i,j)) dfs1(i,j,1);
    ll ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(check_end(i,j)) ans+=dfs2(i,j),ans%=mod;
    printf("%lld",ans);
    return 0;
}