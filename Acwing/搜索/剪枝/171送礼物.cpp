#include <bits/stdc++.h>
#define ll long long
using namespace std;
int w,n,g[50],k;
ll sum[(1<<23)+100],res,cnt;
void dfs1(int now,ll tot=0){
    if(tot>w) return;
    if(now==k+1){
        sum[++cnt]=tot;
        return;
    }
    dfs1(now+1,tot);
    dfs1(now+1,tot+g[now]);
}
void dfs2(int now,ll tot=0){
    if(tot>w) return;
    if(now==n+1){
        int l=1,r=cnt;
        while(l<=r){
            int mid=(l+r)>>1;
            if(tot+sum[mid]<=w) l=mid+1;
            else r=mid-1;
        }
        res=max(res,tot+sum[l-1]);
        return;
    }
    dfs2(now+1,tot);
    dfs2(now+1,tot+g[now]);
}
int main(){
    scanf("%d%d",&w,&n);
    for(int i=1;i<=n;i++) scanf("%d",&g[i]);
    sort(g+1,g+1+n);
    reverse(g+1,g+1+n);
    k=n/2;
    dfs1(1);
    sort(sum+1,sum+1+cnt);
    cnt=unique(sum+1,sum+1+cnt)-(sum+1);
    dfs2(k+1);
    printf("%lld",res);
    return 0;
}