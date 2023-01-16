#include <bits/stdc++.h>
using namespace std;
int a[15000],n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long ans=0;
    for(int i=0;i<k;i++){
        ans+=a[n-i];
    }
    cout<<ans;
    return 0;
}