#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;
ll qpow(ll a,ll b){
    if(b==0) return 1;
    auto tmp=qpow(a,b>>1);
    tmp*=tmp;
    tmp%=MOD;
    if(b&1) tmp*=a;
    return tmp%MOD;
}
int n;
ll f[2500][2500],g[2500][2500],w[2500],p[2500],tmp1[2500],tmp2[2500],ans[2500];
int siz[2500],fa[2500];
vector<int>G[2500];
void dfs(int now,int pre){
    fa[now]=pre;
    f[now][1]=p[now],f[now][0]=((1-p[now])%MOD+MOD)%MOD;
    g[now][1]=w[now];
    siz[now]=1;
    for(auto nxt:G[now]){
        if(nxt==pre) continue;
        dfs(nxt,now);
        memset(tmp1,0,sizeof(tmp1));
        memset(tmp2,0,sizeof(tmp2));
        for(int i=1;i<=siz[now];i++){
            for(int j=0;j<=siz[nxt];j++){
                tmp1[i+j]+=f[now][i]*f[nxt][j]%MOD;
                tmp1[i+j]%=MOD;
                tmp2[i+j]+=(g[now][i]*f[nxt][j])%MOD;
                tmp2[i+j]%=MOD;
                if(j){
                    tmp2[i+j]+=f[now][i]*g[nxt][j]%MOD;
                    tmp2[i+j]%=MOD;
                }
            }
        }
        for(int i=1;i<=siz[now]+siz[nxt];i++) f[now][i]=tmp1[i],g[now][i]=tmp2[i];
        siz[now]+=siz[nxt];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        ll a,b;
        scanf("%lld%lld%lld",&w[i],&a,&b);
        sum+=w[i];
        p[i]=a*qpow(b,MOD-2)%MOD;
    }
    sum=qpow(sum,MOD-2);
    for(int i=1;i<=n;i++) w[i]=w[i]*sum%MOD;
    dfs(1,0);
    // cout<<f[1][0]<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // cout<<g[j][i]<<" ";
            if(fa[j]==0) ans[i]+=g[j][i];
            else ans[i]+=g[j][i]*f[fa[j]][0]%MOD;
            ans[i]%=MOD;
        }
        // printf("%lld\n",ans[i]);
    }
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}