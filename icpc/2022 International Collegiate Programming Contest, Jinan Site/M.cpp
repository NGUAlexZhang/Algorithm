#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150000];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll ans=0,add=0;
    for(int j=1;j<=20;j++){
        ll sum=add;
        for(int i=1;i<=n;i++){
            sum+=a[i]%10;
            a[i]/=10;
        }
        ans+=sum/10;
        add=sum/10;
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}