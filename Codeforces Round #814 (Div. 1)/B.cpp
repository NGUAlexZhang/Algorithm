#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll f[150],sum[150],c[150],maxn;
map<ll,int>mp;
void solve(){
    maxn=0;
    int k;
    scanf("%d",&k);
    ll tot=0;
    for(int i=1;i<=k;i++){
        c[i]=0;
        scanf("%lld",&c[i]);
        tot+=c[i];
    }
    int m=mp[tot];
    if(m==0){
        puts("No");
        return;
    }
    int las=0;
    while(m){
        int maxindex=0;
        for(int j=1;j<=k;j++){
            if(j==las) continue;
            if(c[j]>c[maxindex]) maxindex=j;
        }
        if(c[maxindex]<f[m]){
            puts("No");
            return;
        }
        las=maxindex;
        c[maxindex]-=f[m];
        m--;
    }
    for(int i=1;i<=k;i++){
        if(c[i]!=0){
            puts("No");
            return;
        }
    }
    puts("Yes");
}
int main(){
    f[1]=1,f[2]=1;
    for(int i=3;i<=100;i++){
        f[i]=f[i-1]+f[i-2];
    }
    for(int i=1;i<=100;i++){
        sum[i]=sum[i-1]+f[i];
        mp[sum[i]]=i;
    }
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}