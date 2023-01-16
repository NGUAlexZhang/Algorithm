#include <bits/stdc++.h>
#define ll long long
const int MOD=1e9+7;
ll qpow(ll A,ll B){
    if(B==0) return 1;
    ll tmp=qpow(A,B/2);
    tmp*=tmp;
    tmp%=MOD;
    if(B%2) tmp*=A;
    return tmp%MOD;
}
using namespace std;
int main(){
    ll num=qpow(6,MOD-2);
    int T;
    scanf("%d",&T);
    while(T--){
        ll n;
        scanf("%lld",&n);
        ll ans=n*(n+1);
        ans%=MOD;
        ans*=(4*n-1);
        ans%=MOD;
        ans*=num;
        ans%=MOD;
        printf("%lld\n",(ans*2022)%MOD);
    }
    return 0;
}