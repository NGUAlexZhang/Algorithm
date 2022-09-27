#include <bits/stdc++.h>
using namespace std;
const int N=3e5+500;
int a[N],n,dfn[N],fa[N],top[N],siz[N],rnk[N],cnt,dep[N],son[N],sub[N];
vector<int>G[N];
struct Seg{
  int sum[N<<2],lazy[N<<2];
  void push_down(int rt,int l,int r){
    int mid=(l+r)>>1;
    sum[rt<<1]+=(mid-l+1)*lazy[rt];
    sum[rt<<1|1]+=(r-mid)*lazy[rt];
    lazy[rt<<1]+=lazy[rt];
    lazy[rt<<1|1]+=lazy[rt];
    lazy[rt]=0;
  }
  void push_up(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
  }
  void add(int rt,int l,int r,int L,int R,int x){
    if(l>=L&&r<=R){
        lazy[rt]+=x;
        sum[rt]+=(r-l+1)*x;
        return;
    }
    // cout<<L<<"   "<<R<<endl;
    push_down(rt,l,r);
    int mid=(l+r)>>1;
    if(L<=mid) add(rt<<1,l,mid,L,R,x);
    if(R>mid) add(rt<<1|1,mid+1,r,L,R,x);
    push_up(rt);
  } 
  int query(int rt,int l,int r,int L,int R){
    if(l>=L&&r<=R){
        return sum[rt];
    }
    push_down(rt,l,r);
    int sum=0;
    int mid=(l+r)>>1;
    if(L<=mid) sum+=query(rt<<1,l,mid,L,R);
    if(R>mid) sum+=query(rt<<1|1,mid+1,r,L,R);
    return sum;
  }
}st;
void dfs1(int now,int pre,int d=1){
    siz[now]=1,fa[now]=pre,dep[now]=d;
    for(auto nxt:G[now]){
        if(nxt==pre) continue;
        dfs1(nxt,now,d+1);
        if(siz[son[now]]<siz[nxt]) son[now]=nxt;
        siz[now]+=siz[nxt];
    }
}

void dfs2(int now,int pre){
    top[now]=pre,dfn[now]=++cnt,rnk[cnt]=now;
    if(son[now]) dfs2(son[now],pre);
    for(auto nxt:G[now]){
        if(nxt==fa[now]||nxt==son[now]) continue;
        dfs2(nxt,nxt); 
    }
}
void add(int x,int y){
    int fx=top[x],fy=top[y];
    while(fx!=fy){
        if(dep[fx]>=dep[fy]){
            st.add(1,1,n,dfn[fx],dfn[x],1);
            x=fa[fx];
        }
        else{
            st.add(1,1,n,dfn[fy],dfn[y],1);
            y=fa[fy];
        }
        fx=top[x],fy=top[y];
    }
    if(dfn[x]>dfn[y]){
        st.add(1,1,n,dfn[y],dfn[x],1);
    }
    else{
        st.add(1,1,n,dfn[x],dfn[y],1);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }   
    dfs1(1,0);
    dfs2(1,1);
    for(int i=1;i<n;i++){
        add(a[i],a[i+1]);       
    }
    for(int i=2;i<=n;i++) sub[a[i]]++;
    for(int i=1;i<=n;i++) printf("%d\n",st.query(1,1,n,dfn[i],dfn[i])-sub[i]);
    return 0;
}
/*
8
6 2 1 6 8 3 2 6 
6 1
5 8
3 1
2 6
8 7
4 6
7 4


3
2
1
2
0
5
2
1
*/l