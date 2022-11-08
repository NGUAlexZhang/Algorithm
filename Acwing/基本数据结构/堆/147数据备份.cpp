#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool del[150000];
ll a[150000];
int pre[150000],nxt[150000];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<n;i++) a[i]=a[i+1]-a[i];
    for(int i=1;i<n;i++) pre[i]=i-1,nxt[i]=(i+1==n)?0:i+1;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
    for(int i=1;i<n;i++){
        q.push(make_pair(a[i],i));
    }
    a[0]=1e10;
    long long ans=0;
    for(int i=1;i<=k;i++){
        auto e=q.top();
        q.pop();
        while(del[e.second]){
            e=q.top();
            q.pop();
        }
        ans+=e.first;
        if(pre[e.second]!=0) del[pre[e.second]]=1;
        if(nxt[e.second]!=0) del[nxt[e.second]]=1;
        a[e.second]=a[pre[e.second]]+a[nxt[e.second]]-a[e.second];
        q.push(make_pair(a[e.second],e.second));
        if(pre[e.second]!=0)
            pre[e.second]=pre[pre[e.second]];
        if(nxt[e.second]!=0)
            nxt[e.second]=nxt[nxt[e.second]];
        pre[nxt[e.second]]=e.second;
        nxt[pre[e.second]]=e.second;
    }
    printf("%lld",ans);
    return 0;
}