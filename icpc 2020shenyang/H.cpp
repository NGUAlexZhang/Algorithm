#include <bits/stdc++.h>
using namespace std;
struct Card{
    int d,k,c;
}card[1500];
int a[350000],dp[350000],b[350000];
int main(){
    int n,m,k,tot=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&card[i].d,&card[i].k,&card[i].c);
    }
    for(int i=1;i<=m;i++){
        int p,q;
        scanf("%d%d",&p,&q);
        while(q--){
            a[++tot]=p;
        }
    }
    sort(a+1,a+1+tot);
    for(int i=1;i<=n;i++) b[i]=1;
    for(int i=1;i<=tot;i++){
        dp[i]=dp[i-1]+k;
        for(int j=1;j<=n;j++){
            // int l=1,r=i;
            // while(l<=r){
            //     int mid=(l+r)/2;
            //     if(a[mid]+card[j].d-1>=a[i]&&mid+card[j].k-1>=i) r=mid-1;
            //     else l=mid+1;
            // }
            while(a[b[j]]+card[j].d-1<a[i]||b[j]+card[j].k-1<i) b[j]++;
            dp[i]=min(dp[i],dp[b[j]-1]+card[j].c);

        }
    }
    printf("%d ",dp[tot]);
    return 0;
}