#include <bits/stdc++.h>
using namespace std;
int a[150][150];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
    int ans=-1e9;
    for(int up=1;up<=n;up++)
    for(int low=up;low<=n;low++){
        int minn=0;
        for(int i=1;i<=n;i++){
            int num=a[low][i]-a[up-1][i];
            ans=max(ans,num-minn);
            minn=min(minn,num);
        }
    }
    printf("%d",ans);
    return 0;
}