#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[350000],sum[350000];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll ans=-1e15;
    deque<int>q;
    q.push_front(0);
    for(int i=1;i<=n;i++){
        while(q.size()&&i-m>q.front()) q.pop_front();
        ans=max(ans,sum[i]-sum[q.front()]);
        while(q.size()&&sum[q.back()]>=sum[i]) q.pop_back();
        q.push_back(i);
    }
    printf("%lld",ans);
    return 0;
}