#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[150000];
ll gcd(ll A,ll B){
    if(B==0) return A;
    return gcd(B,A%B);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        bool flag=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int las=a[1],now=a[1];
        for(int i=2;i<=n;i++){
            ll num=a[i];
            ll g=gcd(now,num);
            now/=g;
            now*=num;
            g=gcd(now,las);
            if(g!=a[i-1]){
                puts("NO");
                flag=0;
                break;
            }
            las=now;
            now=num;
        }
        if(flag) puts("YES");
    }
    return 0;
}