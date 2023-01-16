#include <bits/stdc++.h>
using namespace std;
int T,a[150000],sum[150000],dp[150000];
int main(){
    scanf("%d",&T);
    while(T--){
        int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]^a[i];
        }
        map<int,int>las;
        las.insert({0,0});
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            if(las.find(sum[i])!=las.end()) {dp[i]=min(dp[i],dp[las[sum[i]]]+(i-las[sum[i]]-1));}
            las[sum[i]]=i;
        }
        // for(int i=1;i<=n;i++)
        // printf("%d ",las[sum[i]]);
        // puts("");
        printf("%d\n",dp[n]);
    }
    return 0;
}