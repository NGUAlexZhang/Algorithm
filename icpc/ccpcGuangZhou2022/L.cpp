#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll jie[150000];
ll qpow(ll a,ll b){
    if(b==0) return 1;
    ll tmp=qpow(a,b>>1);
    tmp*=tmp;
    tmp%=MOD;
    if(b&1) tmp*=a;
    return tmp%MOD;
}
ll C(ll a,ll b){
    return jie[a]*qpow(jie[b],MOD-2)%MOD*qpow(jie[a-b],MOD-2)%MOD;
}
int main(){
    jie[0]=1;
    for(int i=1;i<=100000;i++){
        jie[i]=jie[i-1]*i;
        jie[i]%=MOD;
    }
    int T;
    cin>>T;
    while(T--){
        ll n,m,ans=1;
        cin>>n>>m;
        cout<<jie[n]*C(n-1,m-1)%MOD<<endl;
    }
    return 0;
}