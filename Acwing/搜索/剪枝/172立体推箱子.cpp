#include <bits/stdc++.h>
using namespace std;
char s[505][505];
int dx[3][4]={
    {0,0,-2,1},
    {0,0,-1,2},
    {0,0,-1,1}
},
dy[3][4]={
    {-2,1,0,0},
    {-1,1,0,0},
    {-1,2,0,0}
},
ds[3][4]={
    {2,2,1,1},
    {1,1,0,0},
    {0,0,2,2}
};
int ans[505][505][3];
struct Node{
    int x,y,state;
    Node(int x,int y,int state){
        this->x=x,this->y=y,this->state=state;
    }
};
int n,m,sx,sy,ex,ey,state;
int bfs(){
    queue<Node>q;
    memset(ans,-1,sizeof(ans));
    ans[sx][sy][state]=0;
    q.push(Node(sx,sy,state));
    while(q.size()){
        auto node=q.front();
        q.pop();
        auto nx=node.x,ny=node.y,ns=node.state;
        if(nx==ex&&ny==ey&&ns==0) return ans[ex][ey][0];
        for(int i=0;i<4;i++){
            auto kx=nx+dx[ns][i],ky=ny+dy[ns][i],ks=ds[ns][i];
            auto ax=kx,ay=ky;
            
            if((kx<1||kx>n)||(ky<1||ky>m)||(s[kx][ky]=='#')) continue;
            if(ks==1) ax++;
            if(ks==2) ay++;
            
            if((ax<1||ax>n)||(ay<1||ay>m)||(s[ax][ay]=='#')) continue;
            if(ks==0&&s[kx][ky]=='E') continue;
            if(ans[kx][ky][ks]==-1){
                ans[kx][ky][ks]=ans[nx][ny][ns]+1;
                q.push(Node(kx,ky,ks));
            }
        }
    }
    return -1;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(!n||!m) return 0;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(s[i][j]=='X'){
                s[i][j]='.';
                sx=i,sy=j;
                if(s[i+1][j]=='X') state=1,s[i+1][j]='.';
                else if(s[i][j+1]=='X') state=2,s[i][j+1]='.';
                else state=0;
            }
            if(s[i][j]=='O'){
                ex=i,ey=j;
                s[i][j]='.';
            }
        }
        auto res=bfs();
        if(res==-1) puts("Impossible");
        else printf("%d\n",res);
    }
    return 0;
}