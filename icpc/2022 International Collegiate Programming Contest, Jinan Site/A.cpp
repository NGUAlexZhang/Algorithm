#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1500];
void solve(){
    ll ans=1e15;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        vector<int>v;
        ll sum=0;
        for(int j=i+1;j<=n;j++){
            int num=a[j],minn=a[j]-a[i],cnt=0;
            while(num>=a[i]){
                minn=min(minn,cnt+abs(num-a[i]));
                num/=2;
                cnt++;
            }
            if(num) minn=min(minn,cnt+abs(num-a[i]));
            v.push_back(minn);
            sum+=minn;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ll tot=0;
        for(int j=m+1;j<i;j++){
            tot+=abs(a[i]-a[j]);
        }
        int p1=min(m,i-1);
        int p2=m-p1;
        for(int j=0;j<p2;j++){
            sum-=v[j];
        }
        while(true){
            ans=min(ans,sum+tot);
            // cout<<ans<<endl;
            if(p1==0||p2==v.size()) break;
            tot+=abs(a[p1]-a[i]);
            p1--;
            p2++;
            sum-=v[p2-1];
        }
    }
    for(int i=1;i<=n;i++){
        int now=a[i];
        now/=2;
        while(now){
            vector<int>small,big,v;
            for(int j=1;j<=n;j++){
                if(a[j]<=now) small.push_back(a[j]);
                else big.push_back(a[j]);
            }
            ll sum=0;
            sort(small.begin(),small.end());
            for(auto it:big){
                int num=it,minn=abs(it-now),cnt=0;
                while(num>=now){
                    minn=min(minn,cnt+abs(num-now));
                    num/=2;
                    cnt++;
                }
                if(num) minn=min(minn,cnt+abs(num-now));
                v.push_back(minn);
                sum+=minn;
            }
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            ll tot=0;
            for(int j=m+1;j<=small.size();j++){
                tot+=abs(now-small[j-1]);
            }
            int p1=min(m,int(small.size()));
            int p2=m-p1;
            for(int j=0;j<p2;j++){
                sum-=v[j];
            }

            // if(now==3){
            //     for(auto it:small) cout<<it<<" ";
            //     puts("");
            //     // cout<<sum<<"   "<<tot<<endl;
            // }
            while(true){
                ans=min(ans,sum+tot);
                if(p1==0||p2==v.size()) break;
                tot+=abs(now-small[p1-1]);
                p1--;
                p2++;
                sum-=v[p2-1];
            }
            now/=2;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}