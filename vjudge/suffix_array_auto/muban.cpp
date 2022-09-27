#include <bits/stdc++.h>
using namespace std;
char s[1500000];
struct Node{
  int fa,ch[27],len;  
}node[1500000<<1];
int cnt=1,las=1,siz[1500000<<1],c[1500000<<1],a[1500000<<1];
long long ans;
void insert(int c){
    int p=las,np=++cnt;
    las=np;
    node[np].len=node[p].len+1;
    siz[np]=1;
    for(;p&&!node[p].ch[c];p=node[p].fa) node[p].ch[c]=np;
    if(!p){node[np].fa=1;return;}
    int q=node[p].ch[c];
    if(node[q].len==node[p].len+1){
        node[np].fa=q;
        return;
    }
    int nq=++cnt;
    node[nq]=node[q];
    node[nq].len=node[p].len+1;
    node[np].fa=nq;node[q].fa=nq;
    for(;p&&node[p].ch[c]==q;p=node[p].fa) node[p].ch[c]=nq;
}
void calc(){
    for(int i=1;i<=cnt;i++) c[node[i].len]++;
    for(int i=1;i<=cnt;i++) c[i]+=c[i-1];
    for(int i=1;i<=cnt;i++) a[c[node[i].len]--]=i;
    for(int i=cnt;i;i--){
        int now=a[i];
        siz[node[now].fa]+=siz[now];
        // cout<<siz[now]<<"  "<<node[now].len<<endl;
        if(siz[now]>1) ans=max(ans,node[now].len*1ll*siz[now]);
    }
}
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++) insert(s[i]-'a'+1);
    // for(int i=1;i<=cnt;i++) siz[i]=1;
    calc();
    cout<<ans<<endl;
    cout<<cnt;
    return 0;
}