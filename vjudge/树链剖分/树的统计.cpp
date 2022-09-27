#include <bits/stdc++.h>
using namespace std;
vector<int>G[350000];
int n,dfn[350000],top[350000],son[350000],fa[350000],siz[350000],cnt,rnk[350000],w[350000],dep[350000];
struct SegTree{
    int maxn[350000],sum[350000];
    void build(int rt,int l,int r){
        if(l==r){
            maxn[rt]=w[rnk[l]];
            sum[rt]=w[rnk[l]];
            return;
        }
        int mid=(l+r)/2;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    }
    void update(int rt,int l,int r,int L,int x){
        if(l==r){
            maxn[rt]=x;
            sum[rt]=x;
            return;
        }
        int mid=(l+r)/2;
        if(L<=mid) update(rt<<1,l,mid,L,x);
        else update(rt<<1|1,mid+1,r,L,x);
        maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    }
    int queryMax(int rt,int l,int r,int L,int R){
        if(l>=L&&r<=R){
            return maxn[rt];
        }
        int mid=(l+r)/2;
        int ans=-50000;
        if(L<=mid) ans=max(ans,queryMax(rt<<1,l,mid,L,R));
        if(R>mid) ans=max(ans,queryMax(rt<<1|1,mid+1,r,L,R));
        return ans;
    }
    int querySum(int rt,int l,int r,int L,int R){
        if(l>=L&&r<=R){
            return sum[rt];
        }
        int mid=(l+r)/2;
        int sum=0;
        if(L<=mid) sum+=querySum(rt<<1,l,mid,L,R);
        if(R>mid) sum+=querySum(rt<<1|1,mid+1,r,L,R);
        return sum;
    }
}st;
void dfs1(int now,int pre,int d=1){
    siz[now]=1,fa[now]=pre,dep[now]=d;
    for(auto nxt:G[now]){
        if(nxt==pre) continue;
        dfs1(nxt,now,d+1);
        siz[now]+=siz[nxt];
        if(siz[nxt]>siz[son[now]]) son[now]=nxt;
    }
}
void dfs2(int now,int pre){
    dfn[now]=++cnt;
    rnk[cnt]=now;
    top[now]=pre;
    if(son[now]) dfs2(son[now],pre);
    for(auto nxt:G[now]){
        if(nxt==fa[now]||nxt==son[now]) continue;
        dfs2(nxt,nxt);
    }
}
int querySum(int x,int y){
    int fx=top[x],fy=top[y],sum=0;
    while(fx!=fy){
        if(dep[fx]>=dep[fy]){
            sum+=st.querySum(1,1,n,dfn[fx],dfn[x]);
            x=fa[fx];
        }
        else{
            sum+=st.querySum(1,1,n,dfn[fy],dfn[y]);
            y=fa[fy];
        }
        fx=top[x],fy=top[y];
    }
    if(dfn[x]<dfn[y])
        sum+=st.querySum(1,1,n,dfn[x],dfn[y]);
    else sum+=st.querySum(1,1,n,dfn[y],dfn[x]);
    return sum;
}

int queryMax(int x,int y){
    int fx=top[x],fy=top[y],ans=-19260817;
    while(fx!=fy){
        if(dep[fx]>=dep[fy]){
            ans=max(ans,st.queryMax(1,1,n,dfn[fx],dfn[x]));
            x=fa[fx];
        }
        else{
            ans=max(ans,st.queryMax(1,1,n,dfn[fy],dfn[y]));
            y=fa[fy];
        }
        fx=top[x],fy=top[y];
    }
    if(dfn[x]<dfn[y])
        ans=max(ans,st.queryMax(1,1,n,dfn[x],dfn[y]));
    else ans=max(ans,st.queryMax(1,1,n,dfn[y],dfn[x]));
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    dfs1(1,0);
    dfs2(1,1);
    st.build(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--){
        string s;
        int u,v;
        cin>>s;
        scanf("%d%d",&u,&v);
        if(s=="CHANGE") st.update(1,1,n,dfn[u],v);
        if(s=="QMAX") printf("%d\n",queryMax(u,v));
        if(s=="QSUM") printf("%d\n",querySum(u,v));
    }
    return 0;
}