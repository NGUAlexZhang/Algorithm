#include <bits/stdc++.h>
using namespace std;
int n,_index,cnt,res[105];
int ans[105][20],r[105][20];
void dfs(int dep){
    if(dep-1>res[n]) return;
    if(ans[n][dep-1]>=n){
        if(ans[n][dep-1]>n) return;
        res[n]=dep-1;
        for(int i=1;i<dep;i++) r[n][i]=ans[n][i];
        return;
    }
    for(int i=1;i<dep;i++){
        ans[n][dep]=ans[n][dep-1]+ans[n][i];
        dfs(dep+1);
    }
}
int main(){
    // scanf("%d",&n);
    for(int i=1;i<=100;i++){
        n=i;
        cnt=_index=0;
        for(int i=0;i<=7;i++){
            if((n>>i)&1){
                cnt++;
                _index=i;
            }
        }
        res[n]=cnt+_index;
        ans[n][1]=1;
        dfs(2);
    }
    while(scanf("%d",&n)!=EOF){
        if(n==0) return 0;
        for(int i=1;i<=res[n];i++){
            printf("%d ",r[n][i]);
        }
        puts("");
    }
    return 0;
}