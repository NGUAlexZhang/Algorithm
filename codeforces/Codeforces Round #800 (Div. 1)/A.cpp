#include <bits/stdc++.h>
#define  ll long long
using namespace std;
ll a[250000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        while(a[n]==0&&n) n--;
        if(n==0){
            puts("Yes");
            continue;
        }
        for(int i=2;i<=n;i++){
            a[i]++;
        }
        ll now=0;
        bool flag=0;
        for(int i=1;i<n;i++){
            ll sub=(a[i]-now);
            if(sub<=0){
                flag=1;
                break;
            }
            now=-(sub-1);
            // cout<<now<<" ";
        }
        // puts("");
        // cout<<now<<endl;
        if(flag||now!=a[n]) puts("No");
        else puts("Yes");
    }
    return 0;
}