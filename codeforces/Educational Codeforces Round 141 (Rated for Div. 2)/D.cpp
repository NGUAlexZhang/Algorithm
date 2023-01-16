#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2][300*300*2+500];
const int MOD=998244353;
int main(){
    int n,x;
    scanf("%d",&n);
    scanf("%d",&x);
    scanf("%d",&x);
    dp[0][300*300+x]=1;
    for(int i=3;i<=n;i++){
        scanf("%d",&x);
        for(int j=0;j<=300*300*2;j++) dp[i%2][j]=0;
        for(int j=0;j<=300*300*2;j++){
            int num=j-300*300;
            dp[i%2][x+num+300*300]+=dp[(i+1)%2][j];
            dp[i%2][x+num+300*300]%=MOD;
            if(num){
                dp[i%2][x-num+300*300]+=dp[(i+1)%2][j];
                dp[i%2][x-num+300*300]%=MOD;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=300*300*2;i++){
        ans+=dp[n%2][i];
        ans%=MOD;
    }
    printf("%lld",ans);
    return 0;
}