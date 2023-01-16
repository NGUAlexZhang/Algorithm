#include <bits/stdc++.h>
using namespace std;
int f[1<<18],g[1<<18],a[20],w;
int main(){
    int n;
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            if(1<<(j-1)&i==0) continue;
            int now=i,pre=i&~(1<<(j-1));
            if(f[now]>=f[pre]+1){
                f[now]=f[pre]+1;
                g[now]=w-a[j];
            }
            if(f[now]>=f[pre]){
                if(f[now]>f[pre]){
                    if(g[pre]>=a[j]){
                        f[now]=f[pre];
                        g[now]=g[pre]-a[j];
                    }
                }
                else{
                    g[now]=max(g[now],g[pre]-a[j]);
                }
            }
        }
    }
    // cout<<f[5]<<"  "<<g[4]<<e    ndl;
    printf("%d",f[(1<<n)-1]);
    return 0;
}