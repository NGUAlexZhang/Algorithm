#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll sum[5000000];
int main(){
    ll x;
    scanf("%lld",&x);
    ll high=0;
    ll num=x;
    while(num){
        num/=2;
        high++;
    }
    for(int i=1;i<(1ll<<high);i++){
        sum[i]=sum[i-1];
        if(gcd((i*x)^x,x)==1){
            sum[i]++;
        }
    }
    int n;
    scanf("%d",&n);
    while(n--){
        long long ans=0;
        long long l,r;
        scanf("%lld%lld",&l,&r);
        if(x==1){
            printf("%lld\n",(r-l)+1);
            continue;
        }
        if(r/(1ll<<high)==l/(1ll<<high)){
            ll L=l%(1ll<<high),R=r%(1ll<<high);
            printf("%lld\n",sum[R]-sum[max(L-1,0ll)]);
            continue;
        }
        ll tmpl=0,tmpr=0;
        if(l%(1ll<<high)!=0){
            ll X=l%(1ll<<high);
            ans+=sum[(1ll<<high)-1]-sum[X-1];
            l=l-X+(1ll<<high);
            
        }
        if((r+1)%(1ll<<high)!=0){
            ll X=(r)%(1ll<<high);
            ans+=sum[X];
            r=((r+1)/(1ll<<high))*(1ll<<high)-1;
        }
        // cout<<l<<"  "<<r<<" "<<(1ll<<high)<<endl;
        ans+=sum[(1ll<<high)-1]*((r-l+1)/(1ll<<high));
        // if(r%(1<<high)!=(1<<high)-1){

        // }
        printf("%lld\n",ans);
    }
    return 0;
}