#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150],dp[150][150];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    for(int j=0;j<=i-2;j++)
    for(int k=0;k<=j;k++){
        int l=(i-k-1);
        dp[i][j]=max(dp[i][j],dp[l][j-k]+1ll*(a[i]-a[l])*(a[i]-a[l]));
    }
    for(int i=1;i<=n;i++){
        if(2*i<=n-2) printf("%lld\n",dp[n][2*i]);
        else printf("%lld\n",dp[n][n-2]);
    }
    return 0;
}