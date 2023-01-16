#include <bits/stdc++.h>
using namespace std;
struct Node{
    int kind,x,y,index;
    Node(int kind,int x,int y,int index){
        this->kind=kind,this->x=x,this->y=y,this->index=index;
    }
    Node(int kind,int x,int index){
        this->kind=kind,this->x=x,this->y=y,this->index=index;
    }
    Node(int kind,int index){
        this->kind=kind;
        this->index=index;
    }
    Node(){}
}p[150];
int T,n;
vector<Node>tr,ch;
bool dfs(int re,int las,int minn,int maxx,int tot){
    if(re==0){
        if(!(tot>=minn&&tot<=maxx)) return 0;
        int ti=maxx-tot;
        for(auto it:ch){
            int l=(it.y-it.x)*20+240,r=(it.y-1)*20+299;
            // cout<<ti<<"   "<<(r-l)<<"  "<<l<<"  "<<r<<endl;
            if(ti-(r-l)>0){
                p[it.index]=Node(1,it.y-it.x+1,240,it.index);
                ti-=(r-l);
                continue;
            }
            int sub=min(it.x-1,ti/20);
            ti-=sub*20;
            p[it.index]=Node(1,it.y-sub,299-ti,it.index);
            ti=0;
        }
        return 1;
    }
    for(int i=las;i<tr.size();i++){
        ch.push_back(tr[i]);
        if(dfs(re-1,i+1,minn+(tr[i].y-tr[i].x)*20+240,maxx+(tr[i].y-1)*20+299,tot)) return 1;
        ch.pop_back();
    }
    return false;
}
void solve(){
    tr.clear(),ch.clear();
    int m,tot,cnt1=0,cnt2=0;
    scanf("%d%d",&m,&tot);
    for(int i=1;i<=n;i++){
        char s[10];
        scanf("%s",s+1);
        if(s[1]=='.') p[i]=Node(0,i);
        if(s[1]=='-'){
            int x;
            scanf("%d",&x);
            p[i]=Node(-1,x,i);
        }
        if(s[1]=='+'){
            int x,y;
            scanf("%d/%d",&x,&y);
            p[i]=Node(1,x,y,i);
            tot-=20*(x-1)+y;
            cnt1++;
        }
        if(s[1]=='?'){
            int x,y;
            scanf("%d%d",&x,&y);
            cnt2++;
            p[i]=Node(2,x,y,i);
            tr.push_back(p[i]);
        }
    }
    if(tot<0||cnt1+cnt2<m||cnt1>m){
        puts("No");
        return;
    }
    int minn=0,maxx=0;
    sort(tr.begin(),tr.end(),[](Node x,Node y){
        return (x.y-x.x)<(y.y-y.x);
    });
    for(int i=0;i<m-cnt1;i++)
        minn+=(tr[i].y-tr[i].x)*20+240;
    sort(tr.begin(),tr.end(),[](Node x,Node y){
        return x.y>y.y;
    });
    for(int i=0;i<m-cnt1;i++)
        maxx+=(tr[i].y-1)*20+299;
    if(!(tot>=minn&&tot<=maxx)){
        puts("No");
        return;
    }
    // cout<<minn<<"  "<<maxx<<"  "<<tot<<endl;
    if(!dfs(m-cnt1,0,0,0,tot)){
        puts("No");
        return;
    }
    puts("Yes");
    for(int i=1;i<=n;i++){
        if(p[i].kind==0) puts(".");
        if(p[i].kind==-1) printf("- %d\n",p[i].x);
        if(p[i].kind==1) printf("+ %d/%d\n",p[i].x,p[i].y);
        if(p[i].kind==2) printf("- %d\n",p[i].y);
    }
}
int main(){
    scanf("%d%d",&T,&n);
    while(T--){
        solve();
    }
    return 0;
}