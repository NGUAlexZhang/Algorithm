#include <bits/stdc++.h>
using namespace std;
vector<int> G[1500000];
int f[1500000],g[1500000],top[1500000],len[1500000];
bool ex[1500000];
void dfs1(int now){
    g[now]=1;
    for(auto nxt:G[now]){
        dfs1(nxt);
        if(g[nxt]+1>g[now]){
            g[now]=g[nxt]+1;
            f[now]=nxt;
        }
    }
}
void dfs2(int now,int t,int l){
    top[now]=t,len[now]=l;
    if(f[now]==0) return;
    dfs2(f[now],t,l+1);
    for(auto nxt:G[now]){
        if(nxt==f[now]) continue;
        dfs2(nxt,nxt,1);
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) G[i].clear(),f[i]=g[i]=top[i]=ex[i]=len[i]=0;
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        ex[x]=1;
        G[x].push_back(i);
    }
    dfs1(1);
    dfs2(1,1,1);
    priority_queue<int>q;
    for(int i=1;i<=n;i++){
        if(ex[i]==0) q.push(len[i]);
    }
    int ans=1500000,cnt=0;
    while(q.size()){
        ans=min(ans,cnt+q.top());
        q.pop();
        cnt++;
    }
    ans=min(ans,cnt);
    printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}