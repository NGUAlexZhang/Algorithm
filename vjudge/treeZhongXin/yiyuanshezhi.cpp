#include <bits/stdc++.h>
using namespace std;
int n,siz[150],totsiz[150],weight[150],tot;
long long ans;
vector<int>G[150];
void dfs(int now,int pre){
    for(auto nxt:G[now]){
        if(nxt==pre) continue;
        dfs(nxt,now);
        totsiz[now]+=totsiz[nxt];
        weight[now]=max(weight[now],totsiz[nxt]);
    }
    weight[now]=max(weight[now],tot-totsiz[now]);
}
void getAns(int now,int pre,int dep){
    ans+=dep*siz[now];
    for(auto nxt:G[now]){
        if(nxt==pre) continue;
        getAns(nxt,now,dep+1);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int w,u,v;
        cin>>w>>u>>v;
        if(u){
            G[i].push_back(u);
            G[u].push_back(i);
        }
        if(v){
            G[i].push_back(v);
            G[v].push_back(i);
        }
        totsiz[i]=siz[i]=w;
        tot+=w;
    }
    dfs(1,0);
    int minw=1;
    for(int i=1;i<=n;i++)
        if(weight[i]<weight[minw]) minw=i;
    getAns(minw,0,0);
    cout<<ans<<"  "<<minw;
    return 0;
}