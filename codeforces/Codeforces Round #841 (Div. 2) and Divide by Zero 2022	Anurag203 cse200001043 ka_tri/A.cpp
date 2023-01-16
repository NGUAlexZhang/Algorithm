#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        long long ans=1;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            ans*=x;
        }
        printf("%lld\n",2022*(ans+n-1));
    }
    return 0;
}