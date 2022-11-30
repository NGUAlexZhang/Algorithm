#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[250000];
int n;
const int MOD=998244353;
ll dp[250000][2][2][2][2][2][2];
ll dfs(int now,int d1,int d2,int d3,int l1,int l2,int l3){
    if(now>n) return (l1&&l2&&l3);
    if(dp[now][d1][d2][d3][l1][l2][l3]!=-1) return dp[now][d1][d2][d3][l1][l2][l3]%MOD;
    ll sum=0;
    for(int i=0;i<=(d1?s[now]-'0':1);i++)
    for(int j=0;j<=(d2?s[now]-'0':1);j++)
    for(int k=0;k<=(d3?s[now]-'0':1);k++){
        sum+=dfs(now+1,d1&&(i==(s[now]-'0')),d2&&(j==(s[now]-'0')),d3&&(k==(s[now]-'0')),
        l1||(i==1&&j==0&&k==0)||(i==0&&j==1&&k==1),l2||(j==1&&i==0&&k==0)||(j==0&&i==1&&k==1),
        l3||(k==1&&i==0&&j==0)||(k==0&&i==1&&j==1));
        sum%=MOD;
    }
    return dp[now][d1][d2][d3][l1][l2][l3]=sum;
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    memset(dp,-1,sizeof(dp));
    printf("%lld",dfs(1,1,1,1,0,0,0));
    return 0;
}