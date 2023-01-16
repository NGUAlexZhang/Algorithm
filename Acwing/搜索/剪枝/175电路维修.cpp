#include <bits/stdc++.h>
using namespace std;
char s[510][510];
vector<pair<int,int>>G[505*505];
int n,m,dis[505*505];
bool vis[505*505];
int dx[]={-1,-1,1,1},dy[]={-1,1,-1,1},kx[]={-1,-1,0,0},ky[]={-1,0,-1,0};
int getIndex(int x,int y){
    if(x<1||x>n+1||y<1||y>m+1) return 0;
    return (x-1)*(m+1)+y;
}
int getVal(int x,int y,int _x,int _y,char c){
    if(c=='/'){
        return (_y-y)*(_x-x)>0;
    }
    return (_y-y)*(_x-x)<0;
}
void solve(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=0;i<=(n+1)*(m+1);i++) G[i].clear();
    // for(int i=1;i<=n+1;i++)
    // for(int j=1;j<=m+1;j++){
    //     auto u=getIndex(i,j);
    //     for(int k=0;k<4;k++){
    //         auto nx=i+dx[k],ny=j+dy[k];
    //         auto v=getIndex(nx,ny);
    //         if(v==0) continue;
    //         auto val=getVal(i,j,nx,ny,s[i+kx[k]][j+ky[k]]);
    //         // if(i==1&&j==1){
    //         //     cout<<v<<"  "<<nx<<"  "<<ny<<"  "<<val<<endl;
    //         // }
    //         G[u].push_back({v,val});
    //     }
    // }
    deque<pair<int,int>>q;
    q.push_front({0,1});
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    while(q.size()){
        auto node=q.front();
        q.pop_front();
        auto u=node.second;
        if(u==(n+1)*(m+1)) break;
        if(vis[u]) continue;
        vis[u]=1;
        int x=(u/(m+1))+(u%(m+1)!=0),y=(u-1)%(m+1)+1;
        for(int i=0;i<4;i++){
            auto nx=x+dx[i],ny=y+dy[i];
            auto v=getIndex(nx,ny);
            if(v==0) continue;
            auto val=getVal(x,y,nx,ny,s[x+kx[i]][y+ky[i]]);
            if(dis[v]>dis[u]+val){
                dis[v]=dis[u]+val;
                if(val)
                    q.push_back({dis[v],v});
                else q.push_front({dis[v],v});
            }
        }
    }
    if(dis[(n+1)*(m+1)]==1061109567) puts("NO SOLUTION");
    else
        printf("%d\n",dis[(n+1)*(m+1)]);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}