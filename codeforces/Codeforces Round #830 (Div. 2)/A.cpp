#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int sum=0;
        scanf("%d",&sum);
        for(int i=2;i<=n;i++){
            int x;
            scanf("%d",&x);
            sum=gcd(sum,x);
        }
        if(sum==1){
            puts("0");
            continue;
        }
        int ans=0;
        if(gcd(sum,n)==1){
            ans=1;
        }
        else if(gcd(sum,n-1)==1) ans=2;
        else ans=3;
        printf("%d\n",ans);
    }
}