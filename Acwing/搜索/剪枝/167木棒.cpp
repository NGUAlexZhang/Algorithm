#include <bits/stdc++.h>
using namespace std;
int n,len,cnt,a[150],v[150];
bool dfs(int index,int cab,int las){
    if(index>cnt) return true;
    if(cab==len) return dfs(index+1,0,1);
    int fail=0;
    for(int i=las;i<=n;i++){
        if(!v[i]&&cab+a[i]<=len&&fail!=a[i]){
            v[i]=1;
            if(dfs(index,cab+a[i],i+1)) return true;
            fail=a[i];
            v[i]=0;
            if(cab==0||cab+a[i]==len) return false;
        }
    }
    return false;
}
int main(){
    while(scanf("%d",&n)){
        if(n==0) return 0;
        int maxn=0,sum=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),maxn=max(maxn,a[i]),sum+=a[i];
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        for(int i=1;i<=sum;i++){
            if(i<maxn||sum%i!=0) continue;
            len=i,cnt=sum/i;
            // cout<<len<<"   "<<cnt<<endl;
            memset(v,0,sizeof(v));
            if(dfs(1,0,1)){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}