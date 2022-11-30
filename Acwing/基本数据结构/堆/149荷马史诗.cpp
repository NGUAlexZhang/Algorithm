#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll,int>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    priority_queue<pli,vector<pli>,greater<pli>>q;
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        q.push({x,0});
    }
    while((n-k)%(k-1)){
        q.push({0ll,0});
        n++;
    }
    // cout<<n<<endl;
    ll ans=0;
    while(q.size()!=1){
        ll sum=0;
        int height=0;
        for(int i=1;i<=k;i++){
            sum+=q.top().first;
            height=max(height,q.top().second);
            q.pop();
        }
        ans+=sum;
        height++;
        q.push({sum,height});
    }
    printf("%lld\n%d",ans,q.top().second);
    return 0;
}