#include <bits/stdc++.h>
using namespace std;
int a[150000];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int las=a[1],ans=1,cnt=1;
    for(int i=2;i<=n;i++){
        if(a[i]-las<k) continue;
        las=a[i];
        cnt++;
    }
    ans=max(ans,cnt);
    las=a[n],cnt=1;
    for(int i=n-1;i>=1;i--){
        if(las-a[i]<k) continue;
        las=a[i];
        cnt++;
    }
    ans=max(ans,cnt);
    cout<<ans;
    return 0;
}