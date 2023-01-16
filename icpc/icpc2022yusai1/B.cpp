#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[20],b[20];
int n;
ll ans=1e9+100;
void dfs(int now,ll tot,int num,vector<int>w,int las,int dep=0){
    if(tot>=ans) return;
    if(dep==n){
        ans=min(ans,tot);
        return;
    }
    if(dep+num<n&&(n-las+1)<num) return;
    if(!num){
        ll minn=214748364777;
        int index=-1;
        for(int i=1;i<=n;i++){
            if(w[i]==-1) continue;
            ll tmp=(tot-w[i])/a[i];
            if(tmp*a[i]+w[i]<=tot) tmp++;
            ll tm=w[i]+tmp*a[i];
            if(tm<minn){
                minn=tm;
                index=i;
            }
        }
        ll sum=0;
        
        for(int i=1;i<=n;i++){
            if(w[i]==-1) continue;
            if((minn-w[i])%a[i]==0) sum+=b[i];
        }
        // cout<<minn<<"   "<<dep<<"   "<<sum<<endl;
        tot=minn,num=sum;
        las=1;
    }
    for(int i=las;i<=n;i++){
        if((1<<(n-i))&now) continue;
        w[i]=tot;
        dfs(now|(1<<(n-i)),tot,num-1,w,i+1,dep+1);
        w[i]=-1;    
    }
}
int main(){
    scanf("%d",&n);
    vector<int>w(n+1,-1);
    for(int i=1;i<=n;i++) scanf("%d%d",a+i,b+i);
    for(int i=1;i<=n;i++){
        int j=0;
        while(j*b[i]<n-1) j++;
        ans=min(ans,j*1ll*a[i]);
    }+7
    dfs(0,0,1,w,1);
    printf("%lld",ans);
    return 0;
}