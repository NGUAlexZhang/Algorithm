#include <bits/stdc++.h>
using namespace std;
char s[250000],t[250000];
int kmp[250000],ans[250000],tot[250000];
int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for(int i=2,j=0;i<=m;i++){
        while(j&&t[j+1]!=t[i]) j=kmp[j];
        if(t[j+1]==t[i]) j++;
        kmp[i]=j;
    }
    for(int i=n+1;i<n+m;i++){
        s[i]='$';
    }
    t[m+1]='#';
    for(int i=1,j=0;i<=n;i++){
        while(j&&s[i]!=t[j+1]){
            // if(i==32) cout<<i<<" "<<j<<endl;
            j=kmp[j];
        }
        if(s[i]==t[j+1]) j++;
        ans[j]++;
    }
    for(int i=m;i>=1;i--){
        // cout<<ans[i]<<" ";
        ans[kmp[i]] += ans[i];
    }
    // puts("");
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]-ans[x+1]);
    }
    return 0;
}