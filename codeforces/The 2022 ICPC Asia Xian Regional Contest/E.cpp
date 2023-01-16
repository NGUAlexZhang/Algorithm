#include <bits/stdc++.h>
#define ll long long
using namespace std;
int L[100],R[100];
void to3l(ll x){
    int now=64;
    for(int i=0;i<100;i++) L[i]=-1;
    while(x){
        L[now]=x%3;
        x/=3;
        now--;
    }
}
void to3r(ll x){
    int now=64;
    for(int i=0;i<100;i++) R[i]=-1;
    while(x){
        R[now]=x%3;
        now--;
        x/=3;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll l,r;
        scanf("%lld%lld",&l,&r);
        to3l(l);to3r(r);
        int now=0,ans=0,index=0;
        // for(int i=1;i<=64;i++)
        //     if(L[i]!=-1) cout<<L[i];
        // puts("");
        for(int i=1;i<=64;i++)
            if(R[i]!=-1) cout<<R[i];
        puts("");
        for(int i=1;i<=64;i++){
            if(index==0&&R[i]!=-1) index=i;
            ans+=R[i]+1;
        }
        bool flag=0;
        for(int i=1;i<=64;i++){
            if((R[i]==L[i]&&!flag)||R[i]<=0){
                now+=R[i]+1;
                continue;
            }
            if(index==i){
                if(R[i]==1) ans=max(ans,now+(64-i)*3);
                else  ans=max(ans,now+R[i]+(64-i)*3);
            }
            else
            ans=max(ans,now+R[i]+(64-i)*3);
            now+=R[i]+1;
            if(R[i]>L[i]) flag=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}