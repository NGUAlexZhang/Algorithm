#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x[250000],p[250000];
void solve(){
    map<int,int>mp;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&p[i]);
        mp[x[i]-p[i]+1]++;
        mp[x[i]+p[i]+1]++;
        mp[x[i]+1]-=2;
    }
    ll mx1=-1e15,mx2=-1e15,las=-1e9,now=0,tmp=0;
    for(auto it:mp){
        now+=tmp*(it.first-las);
        tmp+=it.second;
        las=it.first;
        if(now>m){
            mx1=max(mx1,now+it.first-1);
            mx2=max(mx2,now-it.first+1);
        }
    }
    // cout<<mx1<<"   "<<mx2<<endl;
    for(int i=1;i<=n;i++) cout<<((m+p[i]+x[i]>=mx1)&&(m+p[i]-x[i]>=mx2));
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}