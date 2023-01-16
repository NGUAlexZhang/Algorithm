#include <bits/stdc++.h>
using namespace std;
int n,m;
bool in[35000];
vector<int> G[35000];
bitset<30001>f[35000];
void dfs(int now){
    if(f[now].count()) return;
    // cout<<now<<endl;
    f[now][now]=1;
    for(auto nxt:G[now]) dfs(nxt),f[now]|=f[nxt];
}
int main(){
    map<pair<int,int>,bool>mp;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(mp[{x,y}]) continue;
        G[x].push_back(y);
        in[y]=1;
        mp[{x,y}]=1;
    }
    for(int i=1;i<=n;i++){
        if(!in[i]) dfs(i);
    }
    for(int i=1;i<=n;i++) cout<<f[i].count()<<endl;
    return 0;
}