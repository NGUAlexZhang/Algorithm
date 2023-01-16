#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=262143;
int exi[4500000];
vector<int> nums;
int main(){
    nums.push_back(0);
    for(int i=1;i<=maxn;i++){
        int tmp=sqrt(i);
        if(tmp*tmp==i) nums.push_back(i);
    }
    int T;
    scanf("%d",&T);
    while(T--){
        exi[0]=1;
        int n;
        scanf("%d",&n);
        int tmp=n,cnt=0;
        while(tmp){
            tmp>>=1;
            cnt++;
        }
        int m=(1<<cnt)-1;
        for(int i=1;i<=m;i++) exi[i]=0;
        int pre=0;
        ll ans=0;
        for(int i=1;i<=n;i++){
            int add=i;
            int x;
            scanf("%d",&x);
            pre^=x;
            for(auto it:nums){
                if(it>m) break;
                add-=exi[it^pre];
            }
            ans+=add;
            exi[pre]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}