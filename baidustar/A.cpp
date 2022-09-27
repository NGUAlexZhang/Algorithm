#include <bits/stdc++.h>
using namespace std;
struct Seg{
    int a[20],b;
};
int n,m;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        vector<Seg>segs;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            Seg s;
            for(int i=1;i<=n;i++){
                scanf("%d",&s.a[i]);
            }
            scanf("%d",&s.b);
            for(auto& it:segs){
                bool flag=0;
                double d=0;
                for(int i=1;i<=n;i++){
                    if(it.a[i]!=s.a[i]) flag=1;
                }
                if(flag==0){
                    it.b=min(s.b,it.b);
                    break;
                }
            }
        }
        if(segs.size()<n){
            puts("YES");
            continue;
        }
        
    }
    return 0;
}