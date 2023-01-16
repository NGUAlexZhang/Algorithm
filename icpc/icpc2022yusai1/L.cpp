#include <bits/stdc++.h>
using namespace std;
char s[550000],t[550000];
bool vis[100],ban[100][100];
int dp[550000][50];
int main(){
    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=26;j++){
            if(vis[j]) ban[j][t[i]-'a'+1]=true;
        }
        vis[t[i]-'a'+1]=true;
    }
    for(int i=1;i<=n;i++){
        dp[i][s[i]-'a'+1]=1;
        if(!vis[s[i]-'a'+1]){
            for(int j=1;j<=26;j++) dp[i][j]=dp[i-1][j]+1;
            continue;
        }
        for(int j=1;j<=26;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(ban[j][s[i]-'a'+1]) continue;
            dp[i][s[i]-'a'+1]=max(dp[i][s[i]-'a'+1],dp[i-1][j]+1);
        }
    } 
    int ans=0;
    for(int i=1;i<=26;i++) ans=max(ans,dp[n][i]);
    printf("%d",ans);
    return 0;
}