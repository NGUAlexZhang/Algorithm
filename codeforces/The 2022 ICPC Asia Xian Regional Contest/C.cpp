#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        ll now=1,ans=1e18,cnt=0;
        while(now<=c){
            ll tmp=c/now;
            if(c%now) tmp++;
            ans=min(ans,cnt*a+tmp*b);
            now<<=1;
            cnt++;
        }
        ans=min(ans,cnt*a+b);
        printf("%lld\n",ans);
    }
    return 0;
}