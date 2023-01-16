#include <bits/stdc++.h>
using namespace std;
vector<int> num[150000];
int bit[150000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) num[i].clear();
        map<int,int>cnt;
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                int x;
                scanf("%d",&x);
                num[i].push_back(x);
                cnt[x]++;
            }
        }
        bool ex=0;
        for(int i=1;i<=n;i++){
            bool flag=1;
            for(auto it:num[i]){
                if(cnt[it]<2){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ex=1;
                break;
            }
        }
        if(ex) puts("Yes");
        else puts("No");
    }
    return 0;
}