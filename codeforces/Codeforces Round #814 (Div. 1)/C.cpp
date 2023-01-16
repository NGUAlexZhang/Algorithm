#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[50][100000],a[220000];
int divi[1500];
bool prime[250000];
multiset<ll>S[500];
void getprime(){
    const int N=2e5;
    for(int i=2;i<=N;i++){
        if(prime[i]) continue;
        for(int j=i+i;j<=N;j+=i){
            prime[j]=1;
        }
    }
}
void solve(){
    int n,q,cnt=0;
    scanf("%d%d",&n,&q);
    divi[++cnt]=1;
    for(int i=2;i<n;i++){
        if(!prime[i]&&n%i==0){
            divi[++cnt]=n/i;
        }
    }
    // for(int i=1;i<=cnt;i++) cout<<divi[i]<<" ";
    // puts("");
    sort(divi+1,divi+1+cnt);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<divi[i];j++) sum[i][j]=0;
    }
    for(int i=1;i<=cnt;i++){
        S[i].clear();
        for(int j=1;j<=n;j++){
            // cout<<j%divi[i]<<endl;
            sum[i][j%divi[i]]+=a[j];
        }
    }
    // puts("");
    ll ans=0;
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<divi[i];j++){
            S[i].insert(sum[i][j]);
        }
        ans=max(ans,(*S[i].rbegin())*divi[i]);
    }
    printf("%lld\n",ans);
    while(q--){
        int index,x;
        scanf("%d%d",&index,&x);
        int tmp=a[index]-x;
        a[index]=x;
        ans=0;
        for(int i=1;i<=cnt;i++){
            auto mid=sum[i][index%divi[i]];
            S[i].erase(S[i].find(mid));
            sum[i][index%divi[i]]-=tmp;
            S[i].insert(sum[i][index%divi[i]]);
            ans=max(ans,(*S[i].rbegin())*divi[i]);
        }
        printf("%lld\n",ans);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    getprime();
    prime[1]=1;
    while(T--){
        solve();
    }
    return 0;
}