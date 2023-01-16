#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x,y,px,py,step;
    string str;
    Node(int _x,int _y,int _px,int _py,string _str,int _step=0){
        x=_x,y=_y,px=_px,py=_py,step=_step;
        str=_str;
    }
};
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
char dir2[]={'n','s','w','e'},dir1[]={'N','S','W','E'};
int n,m,sx,sy,bx,by,tx,ty;
int ans[25][25][4],ans2[25][25];
string res;
char s[25][25];
string bfs2(int px,int py,int _tx,int _ty,int _x,int _y){
    memset(ans2,-1,sizeof(ans2));
    queue<pair<pair<int,int>,string>>q;
    q.push({{px,py},""});
    ans2[px][py]=0;
    
    while(q.size()){
        auto node=q.front();
        q.pop();
        auto point=node.first;
        auto anss=node.second;
        auto x=point.first,y=point.second;
        // if(px==6&&py==4&&_tx==4&&_ty==4){
        //     // puts("sb");
        //     // printf("%d %d %d %d\n",x,y,_x,_y);
        // }
        if(x==_tx&&y==_ty){
            return anss;
        }
        for(int i=0;i<4;i++){
            auto nx=x+dx[i],ny=y+dy[i];
            // if(px==6&&py==4&&_tx==4&&_ty==4){
            //     cout<<x<<"  "<<y<<"  "<<nx<<" "<<ny<<"  "<<dx[i]<<"  "<<dy[i]<<endl;    
            // }
            if(nx<1||nx>n||ny<1||ny>m||(nx==_x&&ny==_y)) continue;
            if(s[nx][ny]=='#') continue;
            if(ans2[nx][ny]==-1){
                ans2[nx][ny]=ans2[x][y]+1;
                q.push({{nx,ny},anss+dir2[i]});
            }
        }
    }
    return "";
}
void bfs(){
    memset(ans,-1,sizeof(ans));
    queue<Node>q;
    int minn=1000;
    q.push(Node(bx,by,sx,sy,""));
    ans[bx][by]=0;
    while(q.size()){
        auto node=q.front();
        int x=node.x,y=node.y,px=node.px,py=node.py,step=node.step;
        // cout<<x<<"  "<<y<<endl;
        auto anss=node.str;
        q.pop();
        if(ans[tx][ty]!=-1&&step>ans[tx][ty]) return;
        if(x==tx&&y==ty){
            if(anss.size()<minn) res=anss,minn=anss.size();
        }
        for(int i=0;i<4;i++){
            auto nx=x+dx[i],ny=y+dy[i];
            auto _tx=x-dx[i],_ty=y-dy[i];
            
            if(nx<1||nx>n||ny<1||ny>m||s[nx][ny]=='#') continue;
            if(_tx<1||_tx>n||_ty<1||_ty>m||s[_tx][_ty]=='#') continue;
            auto str=bfs2(px,py,_tx,_ty,x,y);
            if(x==3&&y==7){
                cout<<nx<<" "<<ny<<" "<<_tx<<"  "<<_ty<<"  str:"<<str<<"  "<<px<<"  "<<py<<endl;
            }
            if(ans2[_tx][_ty]==-1) continue;
            if(ans[nx][ny][i]==-1||(nx==tx&&ny==ty)){
                ans[nx][ny][i]=ans[x][y]+1;
                q.push(Node(nx,ny,x,y,anss+str+dir1[i],step+1));
            }
        }
    }
}
int main(){
    int cnt=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(!n||!m) return 0;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i][j]=='S') sx=i,sy=j,s[i][j]='.';
                if(s[i][j]=='B') bx=i,by=j,s[i][j]='.';
                if(s[i][j]=='T') tx=i,ty=j,s[i][j]='.';
            }
        }
        res="";
        bfs();
        printf("Maze #%d\n",++cnt);
        if(ans[tx][ty]==-1) puts("Impossible.");
        else cout<<res<<endl;
        puts("");
    }

    return 0;
}