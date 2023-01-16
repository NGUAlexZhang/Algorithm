#include <bits/stdc++.h>
using namespace std;
char s[250000],t[250000];
int kmp[250000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        if(s[1]==s[2]||s[1]=='b'){
            printf("%c %c ",s[1],s[2]);
            for(int i=3;i<=n;i++) printf("%c",s[i]);
            puts("");
            continue;
        }
        printf("%c ",s[1]);
        for(int i=2;i<n;i++) printf("%c",s[i]);
        printf(" ");
        printf("%c\n",s[n]);
    }
    return 0;
}