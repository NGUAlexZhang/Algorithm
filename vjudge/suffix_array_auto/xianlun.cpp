#include <bits/stdc++.h>
using namespace std;
const int N=5e5+500;
int t,kk,ch[N<<1][27],fa[N<<1],len[N<<1],siz[N<<1],sum[N<<1],a[N<<1],c[N<<1];
char s[N];
struct Mechine{
    int tot,last;
    Mechine(){tot=1,last=1;}
    void insert(int c){
        int p=last,nowp=++tot;
        siz[nowp]=1;len[nowp]=len[p]+1;
        last=nowp;
        for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=nowp;
        if(!p) {fa[nowp]=1;return;}
        int q=ch[p][c];
        if(len[q]==len[p]+1){
            fa[nowp]=q;
            return;
        }
        int newq=++tot;
        for(int i=0;i<27;i++) ch[newq][i]=ch[q][i];
        len[newq]=len[p]+1;
        fa[newq]=fa[q];fa[nowp]=fa[q]=newq;
        for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=newq;
        
    }
    void process(){
        for(int i=1;i<=tot;i++) c[len[i]]++;
        for(int i=1;i<=tot;i++) c[i]+=c[i-1];
        for(int i=1;i<=tot;i++) a[c[len[i]]--]=i;
        for(int i=tot;i>=1;i--){
            siz[fa[a[i]]]+=siz[a[i]];
        }
        for(int i=1;i<=tot;i++){
            if(t==0) sum[i]=siz[i]=1;
            else sum[i]=siz[i];
        }
        sum[1]=siz[1]=0;
        for(int i=tot;i>=1;i--)
            for(int j=1;j<=26;j++)
                if(ch[a[i]][j]) sum[a[i]]+=sum[ch[a[i]][j]];
    }
    void Print(int now,int k){
        if(k<=siz[now]) return;
        k-=siz[now];
        for(int i=1;i<=26;i++){
            int nxt=ch[now][i];
            if(!nxt) continue;
            if(sum[nxt]<k){
                k-=sum[nxt];
                continue;
            }
            putchar('a'+i-1);
            Print(nxt,k);
            break;
        }
    }
};
int main(){
    Mechine mechine;
    scanf("%s%d%d",s+1,&t,&kk);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) mechine.insert(s[i]-'a'+1);
    mechine.process();
    if(sum[1]<kk){
        puts("-1");
        return 0;
    }
    mechine.Print(1,kk);
    puts("");
    // cout<<endl<<sum[1];
    // puts("");
    // for(int i=1;i<=mechine.tot;i++) cout<<a[i]<<" "<<siz[a[i]]<<" "<<sum[a[i]]<<"   "<<len[a[i]]<<"  "<<fa[a[i]]<<endl;
    return 0;
}