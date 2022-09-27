#include <bits/stdc++.h>
using namespace std;
char s[1500],t[1500];
int f[1500],kmp[1500];
int main(){
    while(scanf("%s",s+1)){
        if(s[1]=='#') return 0;
        scanf("%s",t+1);
        int n=strlen(s+1),m=strlen(t+1);
        for(int i=0;i<=n;i++) f[i]=0;
        for(int i=2,j=0;i<=m;i++){
            while(j&&t[j+1]!=t[i]) j=kmp[j];
            if(t[j+1]==t[i]) j++;
            kmp[i]=j;
        }
        for(int i=1,j=0;i<=n;i++){
            f[i]=f[i-1];
            while(s[i]!=t[j+1]&&j) j=kmp[j];
            if(s[i]==t[j+1]) j++;
            if(j==m){
                f[i]=max(f[i],f[i-m]+1);
            }
        }
        printf("%d\n",f[n]);
    }
    return 0;
}