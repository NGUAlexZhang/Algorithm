#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[20];
int main(){
    int q;
    scanf("%d",&q);
    map<ll,bool>m;
    map<ll,ll>ans;
    while(q--){
        scanf("%s",s+1);
        if(s[1]=='+'){
            ll x;
            scanf("%lld",&x);
            m[x]=1;
        }
        else{
            ll k;
            scanf("%lld",&k);
            if(ans[k]==0){
                ans[k]=k;
            }
            ll sum=ans[k];
            while(m[sum]){
                sum+=k;
            }
            ans[k]=sum;
            printf("%lld\n",ans[k]);
        }
    }
    return 0;
}