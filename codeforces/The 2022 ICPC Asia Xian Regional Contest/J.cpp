#include <bits/stdc++.h>
using namespace std;
int a[150000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int ans=0;
    if(a[n]>0) ans+=a[n];
    if(a[n-1]>0) ans+=a[n-1];
    printf("%d",ans);
    return 0;
}