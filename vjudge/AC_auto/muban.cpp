#include <bits/stdc++.h>
using namespace std;
struct AC{
    int trie[1500000][27],cnt,e[1500000],fail[1500000];
    void insert(char* s){
        int len=strlen(s+1),u=0;
        for(int i=1;i<=len;i++){
            if(!trie[u][s[i]-'a'+1])
                trie[u][s[i]-'a'+1]=++cnt;
            u=trie[u][s[i]-'a'+1];
        }
        e[u]++;
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
            for(int j=u;j&&e[j]!=-1;j=fail[j]){
                res+=e[j],e[j]=-1;
            }
        }
        return res;
    }
}ac;
char s[1500000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        ac.insert(s);
    }
    ac.build();
    scanf("%s",s+1);
    printf("%d",ac.query(s));
    return 0;
}