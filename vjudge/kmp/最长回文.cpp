#include <bits/stdc++.h>
using namespace std;
char s[250000],t[250000];
int d[250000];
int main(){
    while(scanf("%s",s+1)!=EOF){
        int n=strlen(s+1);
        int len=1;
        t[1]='#';
        for(int i=1;i<=n;i++){
            t[++len]=s[i];
            t[++len]='#';
        }
        int l=0,r=-1,ans=0;
        for(int i=1;i<=len;i++){
            int k=1;
            if(i<=r) k=min(d[r-i+l],r-i+1);
            while(i+k<=len&&i-k>=1&&t[i+k]==t[i-k]){
                k++;
            }
            // printf("%d %d\n",i,k);
            d[i]=k;
            if(i+k-1>r){
                r=i+k-1,l=i-k+1;
            }
            k+=k-1;
            ans=max(ans,k/2);
        }
        printf("%d\n",ans);
    }
    return 0;
}