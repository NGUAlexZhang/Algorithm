#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=1;i<=k;i++){
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+1+k,[](ll x,ll y){
            return x>y;
        });
        ll sum=0,cnt=0;
        bool flag=0;
        for(int i=1;i<=k;i++){
            if(a[i]/m>2){
                sum+=a[i]/m;
                continue;
            }
            if(a[i]/m==2) cnt+=2;
        }
        if(sum+cnt>=n){
            if(sum||cnt%2==n%2){
                puts("Yes");
                continue;
            }
        }
        sum=0,cnt=0;
        flag=0;
        for(int i=1;i<=k;i++){
            if(a[i]/n>2){
                sum+=a[i]/n;
                continue;
            }
            if(a[i]/n==2) cnt+=2;
        }
        if(sum+cnt>=m){
            if(sum||cnt%2==m%2){
                puts("Yes");
                continue;
            }
        }
        puts("No");
    }
    return 0;
}