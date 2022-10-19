#include <bits/stdc++.h>
using namespace std;
int a[250000],st[250000][23];
int getMin(int l,int r){
    int k=log2(r-l+1);
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
void solve(){
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) st[i][0]=a[i]-i;
    for(int i=1;i<=22;i++){
        for(int j=1;(j+(1<<i))-1<=n;j++){
            st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(getMin(i,mid)+(i-1)<0) r=mid-1;
            else l=mid+1;
        }
        int len=l-i;
        ans+=len;
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}