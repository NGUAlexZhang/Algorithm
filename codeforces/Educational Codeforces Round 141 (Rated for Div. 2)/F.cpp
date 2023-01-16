#include <bits/stdc++.h>
using namespace std;
int n,a[3500],b[3500];
bool ua[3500],ub[3500],vis[3500],c[3500];
int G[3500][3500],p[3500];
vector<int>sa[3500],sb[3500];
int cnta,cntb;
bool match(int now){
    for(int i=1;i<=cntb;i++){
        if(G[now][i]==1&&!vis[i]){
            vis[i]=1;
            if(p[i]==0||match(p[i])){
                p[i]=now;
                return true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        if(ua[a[i]]) continue;
        int now=a[i],st=a[i];
        ++cnta;
        sa[cnta].push_back(st);
        ua[st]=1;
        while(a[now]!=st){
            now=a[now];
            sa[cnta].push_back(now);
            ua[now]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(ub[b[i]]) continue;
        int now=b[i],st=b[i];
        ++cntb;
        sb[cntb].push_back(st);
        ub[st]=1;
        while(b[now]!=st){
            now=b[now];
            sb[cntb].push_back(now);
            ub[now]=1;
        }
    }
    for(int i=1;i<=cnta;i++){
        for(auto it:sa[i]){
            for(int j=1;j<=cntb;j++){
                if(G[i][j]) continue;
                for(auto it2:sb[j]){
                    if(it==it2){
                        G[i][j]=1;
                        break;
                    }
                }
            }
        }
    }
    int sum=0;
    for(int i=1;i<=cnta;i++){
        memset(vis,0,sizeof(vis));
        match(i);
    }
    for(int i=1;i<=cntb;i++){
        if(p[i]==0) continue;
        auto index=p[i];
        for(auto it:sb[i]){
            bool flag=0;
            for(auto it2:sa[index]){
                if(it==it2){
                    c[it]=1;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(c[i]==0) ans++;
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        if(c[i]==0) printf("%d ",i);
    return 0;
}