#include <bits/stdc++.h>
using namespace std;
int a[250000],b[250000];
int c[250000];
void solve(){
    vector<pair<int,int>>seg;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) c[i]=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        if(a[i]>b[i]) c[a[i]]++,c[b[i]]--;
    }
    for(int i=1;i<=n;i++){
        c[i]+=c[i-1];
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=i;j<=n;j+=i){
            if(c[j]<0) flag=false;
        }
        if(flag) ans.push_back(i);
    }
    printf("%d\n",int(ans.size()));
    for(auto it:ans){
        printf("%d ",it);
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}