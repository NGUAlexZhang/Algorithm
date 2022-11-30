#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;
ll n,m,jie[100],inv[100],dp[55][20][81*55];
int k;
int bn[100],bm[100];
ll qpow(ll A,ll B){
    if(B==0) return 1;
    ll tmp=qpow(A,B>>1);
    tmp*=tmp;
    tmp%=MOD;
    if(B&1) tmp*=A;
    return tmp%MOD;
}
ll C(ll A,ll B){
    if(A<B) return 0;
    return ((jie[A]*inv[B])%MOD*inv[A-B])%MOD;
}
ll dfs(int index,int y,int now){
    if(now<0||((now*1ll)<<(index-1))>((1ll<<index)-1)*(k/2)*(k-k/2)){
        return 0;
    }
    if(index==0) return now==0;
    if(dp[index][y][now]!=-1) return dp[index][y][now];
    ll sum=0;
    if(bm[index]){
        for(int i=0;i<=k;i++){
            for(int j=0;j<=min(y,i);j++){
                if(y<j||k-y<i-j) continue;
                sum+=dfs(index-1,j,(now-(k-i)*i+bn[index])*2)*C(y,j)%MOD*C(k-y,i-j)%MOD;
                sum%=MOD;
            }
        }
    }
    else{
        for(int i=0;i<=min(k,k-y);i++){
            if(k-y<i) continue;
            sum+=dfs(index-1,y,(now-(k-i)*i+bn[index])*2)*C(k-y,i)%MOD;
            sum%=MOD;
        }
    }
    return dp[index][y][now]=sum;
}
int main(){
    memset(dp,-1,sizeof(dp));
    jie[0]=1;
    for(int i=1;i<51;i++){
        jie[i]=jie[i-1]*i;
        jie[i]%=MOD;
    }
    for(int i=0;i<51;i++){
        inv[i]=qpow(jie[i],MOD-2);
    }
    scanf("%lld%lld%d",&n,&m,&k);
    int cnt=0;
    while(n){
        bn[++cnt]=n&1;
        n>>=1;
    }
    cnt=0;
    while(m){
        bm[++cnt]=m&1;
        m>>=1;
    }
    cout<<dfs(50,k,0);
    return 0;
}