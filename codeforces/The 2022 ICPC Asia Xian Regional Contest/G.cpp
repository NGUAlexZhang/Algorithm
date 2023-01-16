#include <bits/stdc++.h>
using namespace std;
struct Trie{
    struct Node{
        int ex=0;
        Node* nxt[50];
        Node(){
            for(int i=0;i<30;i++) nxt[i]=nullptr;
        }
    };
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(const string& str,int index=0){
        int len=str.size();
        auto now=root;
        for(int i=0;i<len;i++){
            if(now->nxt[str[i]-'a'+1]==nullptr) now->nxt[str[i]-'a'+1]=new Node();
            now=now->nxt[str[i]-'a'+1];
        }
        now->ex=index;
    }
    int query(const string& str){
        int len=str.size();
        auto now=root;
        for(int i=0;i<len;i++){
            if(now->nxt[str[i]-'a'+1]==nullptr) return 0;
            now=now->nxt[str[i]-'a'+1];
        }
        return now->ex;
    }
}trie;
string s[150000];
bool ye[150000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+1+n,[](const string& a,const string& b){
        return a.size()<b.size();
    });
    for(int i=1;i<=n;i++){
        trie.insert(s[i],i);
    }
    for(int i=1;i<=n;i++){
        if(s[i].size()==1){
            ye[i]=1;
            continue;
        }
        bool flag=1;
        string tmp="";
        for(int j=1;j<s[i].size();j++) tmp+=s[i][j];
        int index=trie.query(tmp);
        if(index==0||ye[index]==0) continue;
        tmp="";
        for(int j=0;j<s[i].size()-1;j++) tmp+=s[i][j];
        index=trie.query(tmp);
        if(index==0||ye[index]==0) continue;
        ye[i]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(ye[i]) ans=max(ans,(int)s[i].size());
    printf("%d",ans);
    return 0;
}