#include <bits/stdc++.h>
using namespace std;
int x[1500],y[1500],a[1000][1000],rk1[1000],rk2[1000],sum[1000];
int main(){
    set<int>s1,s2;
    map<int,int>m1,m2;
    int c,n;
    scanf("%d%d",&c,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        s1.insert(x[i]);s2.insert(y[i]);
    }
    int maxx=0,maxy=0;
    int index=0;
    for(auto item:s1){
        m1[item]=++index;
        rk1[index]=item;
    }
    maxx=index;
    index=0;
    for(auto item:s2){
        m2[item]=++index;
        rk2[index]=item;
    }
    maxy=index;
    for(int i=1;i<=n;i++){
        a[m1[x[i]]][m2[y[i]]]=1;
    }
    for(int i=1;i<=maxx;i++){
        for(int j=1;j<=maxy;j++){
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    // cout<<maxx<<"  "<<maxy<<endl;
    // for(int i=1;i<=maxx;i++) cout<<rk1[i]<<"  ";
    // puts("");
    // for(int i=1;i<=maxy;i++) cout<<rk2[i]<<"  ";
    // puts("");
    int ans=1e9;
    for(int i=1;i<=maxx;i++){
        for(int j=i;j<=maxx;j++){
            int width=rk1[j]+1-rk1[i];
            for(int k=1;k<=maxy;k++){
                sum[k]=sum[k-1]+a[j][k]-a[i-1][k]-a[j][k-1]+a[i-1][k-1];
                int y=rk2[k]+1-width;
                int l=1,r=k-1;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(rk2[mid]>=y) r=mid-1;
                    else l=mid+1;
                }
                int num=sum[k]-sum[r];
                if(num>=c){
                    ans=min(ans,width);
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}