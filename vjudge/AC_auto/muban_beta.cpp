#include <bits/stdc++.h>
using namespace std;
struct AC{
    int trie[150000][27],cnt,e[150000],fail[150000],val[150000],num[150000];
    void clear(){
        memset(trie,0,sizeof(trie));
        memset(e,0,sizeof(e));
        memset(fail,0,sizeof(fail));
        memset(val,0,sizeof(val));
        memset(num,0,sizeof(num));
        cnt=0;
    }
    void insert(char* s,int id){
        int len=strlen(s+1),u=0;
        for(int i=1;i<=len;i++){
            if(!trie[u][s[i]-'a'+1])
                trie[u][s[i]-'a'+1]=++cnt;
            u=trie[u][s[i]-'a'+1];
        }
        e[u]=id;
    }
    void build(){
        queue<int>q;
        for(int i=1;i<=26;i++)
            if(trie[0][i]) q.push(trie[0][i]);
        while(q.size()){
            int u=q.front();
            q.pop();
            for(int i=1;i<=26;i++){
                if(trie[u][i])
                    fail[trie[u][i]]=trie[fail[u]][i],q.push(trie[u][i]);
                else
                    trie[u][i]=trie[fail[u]][i];
            }
        }
    }
    int query(char* s){
        int u=0,res=0,len=strlen(s+1);
        for(int i=1;i<=len;i++){
            u=trie[u][s[i]-'a'+1];
            for(int j=u;j;j=fail[j]){
                val[j]++;
            }
        }
        for(int i=1;i<=cnt;i++){
            if(e[i]){
                res=max(res,val[i]);
                num[e[i]]=val[i];
            }
        }
        return res;
    }
}ac;
char s[200][200],t[1500000];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        ac.clear();
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
            ac.insert(s[i],i);
        }
        ac.build();
        scanf("%s",t+1);
        int res=ac.query(t);
        printf("%d\n",res);
        for(int i=1;i<=n;i++){
            if(ac.num[i]==res){
                printf("%s\n",s[i]+1);
            }
        }
    }
    return 0;
}