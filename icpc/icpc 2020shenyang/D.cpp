#include <bits/stdc++.h>
using namespace std;
int a[150000],n,tot,limit;
long long ans;
void dfs(int now,int cnt0,int cnt1,int las){
    if(abs(cnt0-cnt1)-(n-now+1)>limit){
        return;
    }
    if(now>n){
        for(int i=1;i<=n;i++) cout<<(a[i]?'r':'b');
        puts("");
        tot++;
        if(tot==100) exit(0);
        return;
    }
    a[now]=0;
    if(las==0)
        dfs(now+1,cnt0+1,cnt1,las);
    else dfs(now+1,cnt0,cnt1+1,las);
    a[now]=1;
    if(las==0)
        dfs(now+1,cnt0,cnt1+1,las^1);
    else dfs(now+1,cnt0+1,cnt1,las^1);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i+=2){
        ans+=(n-i+1);
    }
    limit=(n%2)^1;
    cout<<ans<<endl;
    dfs(1,1,0,0);
    
    return 0;
}