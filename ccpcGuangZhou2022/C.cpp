#include <bits/stdc++.h>
using namespace std;
int n,m,fa[250000],in[250000],dp[250000],ans[250000];
vector<int>G[250000];
vector<int>F[250000];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void solve(){
    vector<pair<int,int>>edges;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        G[i].clear();
        F[i].clear();
        fa[i]=i;
        in[i]=0,dp[i]=0;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        edges.push_back(make_pair(u,v));
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        int u=i;
        for(auto v:G[u]){
            fa[find(v)]=find(G[u][0]);
        }
    }
    for(auto edge:edges){
        int u=edge.first,v=edge.second;
        F[find(u)].push_back(find(v));
        in[find(v)]++;
    }
    int cnt=0;
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(fa[i]==i){
            cnt++;
            if(!in[i]){
                q.push(i);
                dp[i]=1;
            }
        }
    }
    while(q.size()){
        int u=q.front();
        q.pop();cnt--;
        for(auto v:F[u]){
            dp[v]=max(dp[v],dp[u]+1);
            in[v]--;
            if(in[v]==0){
                q.push(v);
            }
        }
    }
    if(cnt){
        puts("No");
        return;
    }
    puts("Yes");
    for(int i=1;i<=n;i++){
        int ans=dp[find(i)];
        if(find(i)!=1&&G[i].size()) ans-=dp[find(G[i][0])];
        printf("%d ",ans);
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}