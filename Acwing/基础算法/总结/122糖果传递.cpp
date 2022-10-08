#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1500000];
int main(){
    int n;
    ll sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    ll avg=sum/n;
    for(int i=1;i<=n;i++) a[i]-=avg;
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    sort(a+1,a+1+n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=abs(a[i]-a[(n+1)/2]);
    }
    printf("%lld",ans);
    return 0;
}