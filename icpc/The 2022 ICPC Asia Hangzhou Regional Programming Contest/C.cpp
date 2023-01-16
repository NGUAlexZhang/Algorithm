#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[3500],w[3500][20],dp[3500][2];
int main(){
    int n,sum;
    scanf("%d%d",&n,&sum);
    ll tot=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        tot+=a[i];
        for(int j=1;j<=a[i];j++) scanf("%lld",&w[i][j]);
    }
    if(tot<=sum){
        ll ans=0;
        for(int i=1;i<=n;i++) ans+=w[i][a[i]];
        printf("%lld",ans);
        return 0;
    }
    for(int i=0;i<=sum;i++) dp[i][0]=dp[i][1]=-1e16;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=0;j--){
            for(int k=a[i];k>=1;k--){
               if(j-k<0) continue;
               if(k==a[i]) dp[j][0]=max(dp[j][0],dp[j-k][0]+w[i][k]),dp[j][1]=max(dp[j][1],dp[j-k][1]+w[i][k]);
               else dp[j][1]=max(dp[j][1],dp[j-k][0]+w[i][k]);
            }
        }
    }
    ll ans=0;
    ans=max(dp[sum][0],dp[sum][1]);
    printf("%lld",ans);
    return 0;
}