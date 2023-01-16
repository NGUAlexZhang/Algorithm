#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,cnt;
ll a[250000];
int l[250000],r[250000];
void del(int index){
    if(index<1||index>cnt) return;
    int li=l[index],ri=r[index];
    r[li]=ri;
    l[ri]=li;
}
void solve(){
    scanf("%d",&n);
    set<pair<ll,int>>sa,sb;
    cnt=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==0) continue;
        if(cnt==0){
            a[++cnt]=0;
            a[cnt]+=x;
            continue;
        }
        int tmp=a[cnt]/abs(a[cnt]);
        if(tmp*x>0) a[cnt]+=x;
        else a[++cnt]=x;
    }
    if(cnt==0){
        puts("0");
        return;
    }
    for(int i=1;i<=cnt;i++){
        if(a[i]>0) sa.insert({a[i],i});
        else sb.insert({a[i],i});
        l[i]=i-1,r[i]=i+1;
    }
    ll tot=0;
    while(sa.size()&&sb.size()){
        auto n1=*sa.begin(),n2=*sb.rbegin();
        if(abs(n1.first)<abs(n2.first)){
            auto index=n1.second;
            sa.erase(n1);
            tot=abs(n1.first);
            if(r[index]<=cnt&&l[index]>=1){
                sb.erase({a[l[index]],l[index]});
                sb.erase({a[r[index]],r[index]});
                a[l[index]]+=a[r[index]]+tot;
                del(r[index]);
                sb.insert({a[l[index]],l[index]});
            }
            del(index);
        }
        else{
            auto index=n2.second;
            sb.erase(n2);
            tot=abs(n2.first);
            if(r[index]<=cnt&&l[index]>=1){
                sa.erase({a[l[index]],l[index]});
                sa.erase({a[r[index]],r[index]});
                a[l[index]]+=a[r[index]]-tot;
                del(r[index]);
                sa.insert({a[l[index]],l[index]});
            }
            del(index);
        }
    }
    ll ans=0;
    if(sa.size()) ans=abs((*sa.begin()).first);
    else ans=abs((*sb.begin()).first);
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}