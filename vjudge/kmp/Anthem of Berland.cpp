#include <bits/stdc++.h>
using namespace std;
char s[150000],t[150000];
int kmp[150000],f[150000],g[150000],n,m;
bool check(int st){
    for(int i=0;i<m;i++){
        if(s[st+i]!=t[i+1]&&s[st+i]!='?') return false;
    }
    return true;
}
int main(){
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1),m=strlen(t+1);
    for(int i=2,j=0;i<=n;i++){
        while(j&&t[i]!=t[j+1]) j=kmp[j];
        if(t[j+1]==t[i]) ++j;
        kmp[i]=j;
    }
    for(int i=m;i<=n;i++){
        f[i]=f[i-1];
        if(check(i-m+1)){
            g[i]=f[i-m]+1;
            for(int now=kmp[m];now;now=kmp[now]){
                g[i]=max(g[i],g[i-(m-now)]+1);
            }
            f[i]=max(f[i],g[i]);
        }
    }
    cout<<f[n]<<endl;
    return 0;
}