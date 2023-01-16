#include <bits/stdc++.h>
using namespace std;
int n,m,col[150000],cnt,sum[100];
long long ans;
bool flag=0;
vector<pair<int,int>>G[150000];
void dfs(int now,int val,int pre){
    if(flag){
        return;
    }
    if(col[now]!=-1){
        if(col[now]!=val)
            flag=1;
        return;
    }
    cnt++;
    col[now]=val;
    for(int i=0;i<30;i++){
        sum[i]+=((val>>i)&1);
    }
    for(auto edge:G[now]){
        auto nxt=edge.first,w=edge.second;
        if(nxt==pre) continue;
        dfs(nxt,col[now]^w,now);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) col[i]=-1;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            cnt=0;
            for(int i=0;i<30;i++) sum[i]=0;
            dfs(i,0,0);
            for(int i=0;i<30;i++){
                ans+=min(sum[i],cnt-sum[i])*1ll*(1<<i);
            }
        }
        if(flag){
            puts("-1");
            return 0;
        }
    }
    cout<<ans;
    return 0;
}