#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150000];
ll gcd(ll A,ll B){
    if(B==0) return A;
    return gcd(B,A%B);
}
ll exgcd(ll A,ll B,ll& x,ll& y){
    if(B==0){x=1,y=0;return A;}
    ll d=exgcd(B,A%B,x,y);
    ll z=x;x=y;y=z-y*(A/B);
    return d;
}
int main(){
    ll n,m,sum=0;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        sum+=x;
    }
    sum%=m;
    ll g1=gcd(n,(n+1)*n/2);
    ll g2=gcd(m,g1);
    ll ans=sum+((m-sum)/g2)*g2;
    if(ans<m) ans+=g2;
    printf("%lld\n",ans%g2);
    ll k1=0,k2=0;
    exgcd(g1,m,k1,k2);
    k1=k1%m*((ans-sum)/g2)%m;
    k1=(k1%m+m)%m;
    // cout<<k1<<endl;
    ll t1=0,t2=0;
    exgcd(n,(n+1)*n/2,t1,t2);
    // cout<<t1<<"  "<<t2<<endl;
    t1*=k1,t2*=k1;
    // cout<<t1<<"  "<<t2<<endl;
    printf("%lld %lld",(t1%m+m)%m,(t2%m+m)%m);
    return 0;
}