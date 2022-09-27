#include <bits/stdc++.h>
using namespace std;
char s[430000];
int rk[430000],oldrk[430000],sa[430000],cnt[450000],id[430000];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) s[i+n]=s[i];
    n<<=1;
    int m=max(300,n);
    for(int i=1;i<=n;i++)
        ++cnt[rk[i]=s[i]];
    for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
    for(int w=1;w<n;w<<=1){
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) id[i]=sa[i];
        for(int i=1;i<=n;i++) cnt[rk[sa[i]+w]]++;
        for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i>=1;i--) sa[cnt[rk[id[i]+w]]--]=id[i];
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) id[i]=sa[i];
        for(int i=1;i<=n;i++) cnt[rk[sa[i]]]++;
        for(int i=1;i<= m;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i>=1;i--) sa[cnt[rk[id[i]]]--]=id[i];
        for(int i=1;i<=n;i++) oldrk[i]=rk[i];
        rk[sa[1]]=1;
        for(int i=2,p=1;i<=n;i++){
            if(oldrk[sa[i]]==oldrk[sa[i-1]]&&oldrk[sa[i]+w]==oldrk[sa[i-1]+w]){
                rk[sa[i]]=p;
            }
            else{
                rk[sa[i]]=++p;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(sa[i]<=n/2)
            printf("%c",s[sa[i]+n/2-1]);
    }
    return 0;
}