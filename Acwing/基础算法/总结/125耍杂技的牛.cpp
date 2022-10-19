#include <bits/stdc++.h>
using namespace std;
struct Cow{
    int w,s;
}c[55000];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i].w,&c[i].s);
    }
    sort(c+1,c+n+1,[](Cow c1,Cow c2){
        return c2.w-c1.s<c1.w-c2.s;
    });
    int sum=0;
    int ans=-1e9;
    for(int i=n;i>=1;i--){
        ans=max(ans,sum-c[i].s);
        sum+=c[i].w;
    }
    printf("%d",ans);
    return 0;
}