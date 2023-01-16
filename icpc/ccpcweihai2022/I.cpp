#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[55000],b[100],cnt[100],cnt2[100],sub[100];
int n,kk;
bool check(ll x){
    for(int i=1;i<=kk;i++){
        cnt[i]=b[i];
    }
    priority_queue<ll>q;
    for(int i=1;i<=n;i++){
        ll num=a[i]*x;
        if(num)
            q.push(num);
    }
    while(q.size()){
        ll num=q.top();
        q.pop();
        int index=0;
        for(int i=61;i>=1;i--){
            if(((1ll<<(i-1))&num)!=0){
                index=i;
                break;
            }
        }
        bool flag=0;
        for(int i=index+1;i<=kk;i++){
            if(cnt[i]){
                cnt[i]--;
                flag=1;
                break;
            }
        }
        if(flag) continue;
        ll tar=(1ll<<(index-1));
        for(int i=min(kk,index);i>=1;i--){
            ll m=cnt[i]*(1ll<<(i-1));
            if(m<=tar){
                tar-=m;
                cnt[i]=0;
            }
            else{
                ll d=tar/(1ll<<(i-1));
                cnt[i]-=d;
                tar=0;
                break;
            }
        }
        if(tar) return 0;
        num-=(1ll<<(index-1));
        if(num) q.push(num);
    }
    return 1;
}
void solve(){
    scanf("%d%d",&n,&kk);
    ll tot=0,sum=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    for(int i=1;i<=kk;i++){
        scanf("%lld",&b[i]);
        tot+=(1ll<<(i-1))*b[i];
    }
    ll l=0,r=(tot/sum);
    // cout<<sum<<"  "<<tot<<"  "<<r<<endl;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n",l-1);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}