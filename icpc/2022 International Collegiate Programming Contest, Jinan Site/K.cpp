#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        map<int,bool>mp;
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(mp[x+1]==0){
                ans++;
            }
            mp[x]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}