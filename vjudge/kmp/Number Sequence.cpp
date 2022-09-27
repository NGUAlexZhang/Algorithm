#include <cstdio>
using namespace std;
int a[1500000],b[1500000],kmp[1500000];
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    for(int i=2,j=0;i<=m;i++){
        while(j&&b[j+1]!=b[i]) j=kmp[j];
        if(b[j+1]==b[i]) j++;
        kmp[i]=j;
    }
    for(int i=1,j=0;i<=n;i++){
        while(j&&a[i]!=b[j+1]) j=kmp[j];
        if(b[j+1]==a[i]) j++;
        // printf("%d %d %d %d %d\n",i,j,b[j+1],a[i],b[1]);
        if(j==m){
            printf("%d\n",i-j+1);
            return;
        }
    }
    puts("-1");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}