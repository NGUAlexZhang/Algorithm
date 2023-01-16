#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,q,fa[250000],cnt,maxn[250000][27],dep[250000],ab[250000][27];
ll a[250000],w[250000],sub[250000];
vector<int>son[250000];
struct Edge{
    int u,v,w;
}e[250000];
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void kruscal(){
    for(int i=1;i<=m;i++){
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v) continue;
        cnt++;
        fa[u]=cnt,fa[v]=cnt;
        w[cnt]=e[i].w;
        // cout<<cnt<<"    "<<w[cnt]<<endl;
        son[cnt].push_back(u);
        sub[u]=w[cnt]-a[u];
        son[cnt].push_back(v);
        sub[v]=w[cnt]-a[v];
        a[cnt]+=a[u]+a[v];
    }
}
void dfs(int now,int father){
    ab[now][0]=father;
    // cout<<now<<" "<<father<<endl;
    maxn[now][0]=now;
    for(auto nxt:son[now]){
        dfs(nxt,now);
        
    }
}
ll getAns(int x,ll k){
    for(ll i=26;i>=0;i--){
        // cout<<x<<"  "<<sub[maxn[x][i]]<<"   "<<k<<endl;
        if(sub[maxn[x][i]]>k||ab[x][i]==0) continue;
        // cout<<x<<" "<<i<<"   "<<ab[x][i]<<"   "<<maxn[x][i]<<"  "<<sub[maxn[x][i]]<<endl;
        x=ab[x][i];
        
    }
    return a[x];
}


int main(){
    // freopen("data.in","r",stdin);
    // freopen("my.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    cnt=n;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e+1,e+1+m,cmp);
    for(ll i=1;i<=2*n;i++) fa[i]=i;
    kruscal();
    // for(ll i=1;i<=cnt;i++){
    //     if(fa[i]!=i) continue;
    //     dfs(i,0);
    // }
    dfs(cnt,0);
    for(ll i=1;i<27;i++)
    for(ll j=1;j<=cnt;j++){
        ab[j][i]=ab[ab[j][i-1]][i-1];
        if(sub[maxn[j][i-1]]>sub[maxn[ab[j][i-1]][i-1]]) maxn[j][i]=maxn[j][i-1];
        else maxn[j][i]=maxn[ab[j][i-1]][i-1];
        if(sub[ab[j][i-1]]>sub[maxn[j][i]]) maxn[j][i]=ab[j][i-1];
    }
    
    while(q--){
        ll x,k;
        scanf("%lld%lld",&x,&k);
        printf("%lld\n",getAns(x,k)+k);
        // cout<<maxn[x][0]<<endl;
        // cout<<sub[2]<<"   "<<sub[4]<<"  "<<ab[2][1]<<endl;
    }
    // find(3);
    return 0;
}