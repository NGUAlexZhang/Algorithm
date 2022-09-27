#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
int n,siz[4500];
ll g[2500][2],f[4500][2500][2],p[2500];
vector<int>G[4500];
void dfs(int now,int pre){
    siz[now]=1;
    f[now][0][0]=1;
    for(auto nxt:G[now]){
        if(nxt==pre) continue;
        dfs(nxt,now);
        for(int i=0;i<=n+5;i++) g[i][0]=g[i][1]=0;
        for(int i=0;i<=siz[now]/2;i++)
        for(int j=0;j<=siz[nxt]/2;j++){
            g[i+j][0]+=f[now][i][0]*(f[nxt][j][0]+f[nxt][j][1]);
            g[i+j][1]+=f[now][i][1]*(f[nxt][j][0]+f[nxt][j][1]);
            g[i+j+1][1]+=f[now][i][0]*f[nxt][j][0];
            g[i+j][0]%=MOD,g[i+j][1]%=MOD,g[i+j+1][1]%=MOD;
        }
        siz[now]+=siz[nxt];
        for(int i=0;i<=siz[now]/2;i++){
            f[now][i][0]=g[i][0];
            f[now][i][1]=g[i][1];
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<(n*2);i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    p[0]=1;
    for(int i=1;i<=n;i++) p[i]=(p[i-1]*(2*i-1))%MOD;
    ll ans=p[n];
    for(int i=1;i<=n;i++){
        ans+=(f[1][i][0]+f[1][i][1])*p[n-i]*((i%2)?-1:1);
        ans=(ans%MOD+MOD)%MOD;
    }
    printf("%lld",ans);
    return 0;
}