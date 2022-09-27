#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll k;
char s[250000][30];
ll qpow(ll a,ll b){
    if(!b) return 1;
    ll tmp=qpow(a,b>>1);
    tmp*=tmp;
    if(b&1) tmp*=a;
    return tmp;
}
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    long long ans=0;
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=m;i++){
        long long cnt=0;
        for(int j=1;j<=n;j++){
            cnt+=(s[j][i]=='A');
        }
        cnt=cnt*(n-cnt);
        if(cnt>=k) ans++;
    }
    cout<<(qpow(2,ans)-1)*qpow(2,m-ans);
    return 0;
}