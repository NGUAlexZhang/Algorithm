#include <bits/stdc++.h>
using namespace std;
int fa[2500];
char s[2500][2500];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=n;i>=1;i--){
        int las=2;
        for(int j=2;j<=(n-i+1);j++){
            int u=i,v=i+j-1;
            if(s[i][j]=='0') continue;
            if(find(u)==find(v)) {las=j+1;continue;}
            printf("%d %d\n",u,v);
            fa[find(u)]=find(v);
            // cout<<las<<"  "<<u<<endl;
            if(find(i+las-1)!=find(u)){
                printf("%d %d\n",i+las-1,v);
                fa[find(i+las-1)]=find(v);
                for(int k=las+1;k<j;k++){
                    int w=i+k-1;
                    if(find(u)==find(w)) continue;
                    printf("%d %d\n",u,w);
                    fa[find(u)]=find(w);
                }
            }
            las=j+1;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}