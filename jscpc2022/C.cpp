#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1500000],ans[1500000],dp[1500000],s[1500000];
int n,q,p,cnt;
void getAns(int x){
    if(x>p){
        ans[x]=-1e17;
        return;
    }
    int f=1,e=0;
    s[0]=0;
    for(int i=1;i*x<=n;i++){
        int now=i*x;
        while(f-e>0&&now-s[e]>p){
            e++;
        }
        dp[now]=dp[s[e]]+a[now];
        while(f-e>0&&dp[s[f-1]]<=dp[now]){
            f--;
        }
        s[f++]=now;
    }
    int now=n+1;
    while(f-e>0&&now-s[e]>p){
        e++;
    }
    ans[x]=dp[s[e]];
}
int main(){
    scanf("%d%d%d",&n,&q,&p);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++)
        getAns(i);
    while(q--){
        int x;
        scanf("%d",&x);
        if(ans[x]==-1e17) puts("Noob");
        else printf("%lld\n",ans[x]);
    }
    return 0;
}