#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[100],b[100],c[100];
void solve(){
    ll n,x;
    scanf("%lld%lld",&n,&x);
    if(x>n){
        puts("-1");
        return;
    }
    if(n==x){
        printf("%lld\n",n);
        return;
    }
    for(int i=0;i<62;i++){
        a[i]=(n>>i)&1;
        b[i]=(x>>i)&1;
    }
    bool flag=0;
    int index=-1;
    for(int i=61;i>=0;i--){
        if(a[i]==0&&b[i]==1){
            flag=1;
            break;
        }
        if(a[i]==1&&b[i]==0){
            if(index==-1) index=i;
        }
    }
    for(int i=0;i<=index;i++)
        if(b[i]==1) flag=1;
    if(a[index+1]==1) flag=1;
    if(flag){
        puts("-1");
        return;
    }
    index++;
    a[index]=1;
    ll ans=0;
    for(int i=index;i<=62;i++){
        if(a[i]) ans+=(1ll<<i);
    }
    // cout<<index<<"  ";
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}