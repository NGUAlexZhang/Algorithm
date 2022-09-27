#include <bits/stdc++.h>
using namespace std;
char w[1500000],t[1500000];
int kmp[1500000];
int solve(){
    int ans=0;
    scanf("%s",w+1);
    scanf("%s",t+1);
    int n=strlen(w+1),m=strlen(t+1);
    for(int i=2,j=0;i<=n;i++){
        while(j&&w[j+1]!=w[i]) j=kmp[j];
        if(w[i]==w[j+1]) j++;
        kmp[i]=j;
    }
    for(int i=1,j=0;i<=m;i++){
        while(j&&w[j+1]!=t[i]) j=kmp[j];
        if(w[j+1]==t[i]) j++;
        if(j==n){
            ans++;
            j=kmp[j];
        }
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        printf("%d\n",solve());
    }
    return 0;
}