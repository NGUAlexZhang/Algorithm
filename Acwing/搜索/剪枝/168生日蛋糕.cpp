#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int n,m,mins[30],minv[30],res=inf,H[30],R[30];
void dfs(int now,int s,int v){
    if(now==0){
        if(v==n)
            res=min(res,s);
        return;
    }
    if(v+minv[now]>n) return;
    if(s+mins[now]>=res) return;
    if(s+2*(n-v)/R[now+1]>=res) return;
    for(int i=min(R[now+1]-1,(int)sqrt((n-v-minv[now-1])/now));i>=now;i--)
    for(int j=min(H[now+1]-1,(n-v-minv[now-1])/(i*i));j>=now;j--){
        R[now]=i,H[now]=j;
        int t=(now==m)?i*i:0;
        dfs(now-1,s+2*i*j+t,v+i*i*j);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        mins[i]=mins[i-1]+2*i*i;
        minv[i]=minv[i-1]+i*i*i;
    }
    R[m+1]=H[m+1]=inf;
    dfs(m,0,0);
    if(res==inf) res=0;
    printf("%d",res);
    return 0;
}