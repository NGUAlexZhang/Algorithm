#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1500000];
void solve(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) dp[i]=0;
    for(int i=n;i>=2;i--){
        ll k=n/i;
        dp[i]=k*(k-1)/2;
        for(int j=2;i*j<=n;j++) dp[i]-=dp[i*j];
    }
    ll ans=m;
    for(int i=n;i>=2;i--){
        // cout<<i<<"  "<<dp[i]<<endl;
        ll k=min(dp[i]/(i-1),m/(i-1));
        m-=k*(i-1);
        ans+=k;
    }
    if(!m)
        printf("%lld\n",ans);
    else puts("-1");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}