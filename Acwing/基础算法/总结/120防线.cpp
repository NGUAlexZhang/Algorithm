#include <bits/stdc++.h>
using namespace std;
int s[250000],e[250000],d[250000];
int n;
int getSum(int maxn){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(s[i]>maxn) continue;
        int num=(min(maxn,e[i])-s[i])/d[i];
        num++;
        sum+=num;
    }
    return sum;
}
bool check(int l,int r){
    return (getSum(r)-getSum(l-1))%2==1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        bool flag=0;
        int minn=2147483647,maxn=-1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&s[i],&e[i],&d[i]);
            maxn=max(maxn,e[i]),minn=min(minn,s[i]);
        }
        if(getSum(maxn)%2==0){
            puts("There's no weakness.");
            continue;
        }
        int l=minn,r=maxn;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(minn,mid)) r=mid-1;
            else l=mid+1;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if((r+1>=s[i])&&(r+1-s[i])%d[i]==0) cnt++;
        }
        printf("%d %d\n",r+1,cnt);
    }
    return 0;
}   