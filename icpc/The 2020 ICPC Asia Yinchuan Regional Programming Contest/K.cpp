#include <bits/stdc++.h>
using namespace std;
int b[129];
struct Trie{
    struct Node{
        Node* nxt[30];
        int siz,ans;
        Node(){
            for(int i=0;i<30;i++) nxt[i]=nullptr;
            ans=siz=0;
        }
    };
    Node* root,* ptr;
    Trie(){
        root=new Node();
        ptr=root;
    }
    void insert(char* s){
        int len=strlen(s+1);
        auto now=root;
        now->siz++;
        for(int i=1;i<=len;i++){
            if(now->nxt[b[s[i]]]==nullptr) now->nxt[b[s[i]]]=new Node();
            now=now->nxt[b[s[i]]];
            now->siz++;
        }
    }
    void remove(char* s){
        int len=strlen(s+1);
        remove(s,1,len,root);
        root->siz--;
    }
    void remove(char* s,int index,int len,Node* now){
        if(index>len){
            return;
        }
        remove(s,index+1,len,now->nxt[b[s[index]]]);
        // cout<<s[index]<<"  "<<now->nxt[b[s[index]]]->siz<<endl;
        now->nxt[b[s[index]]]->siz--;
        if(now->nxt[b[s[index]]]->siz==0){
            delete now->nxt[b[s[index]]];
            now->nxt[b[s[index]]]=nullptr;
        }
        // now->siz--;
    }
    bool match(char c){
        if(ptr->nxt[b[c]]==nullptr) return 0;
        ptr=ptr->nxt[b[c]];
        return 1;
    }
    void insert(char* s,Trie t2){
        int len=strlen(s+1);
        t2.ptr=t2.root;
        insert(s,1,len,root,t2);
    }
    void insert(char* s,int index,int len,Node* now,Trie t2){
        if(index>len) return;
        if(now->nxt[b[s[index]]]==nullptr) now->nxt[b[s[index]]]=new Node();
        int tmp=now->nxt[b[s[index]]]->ans;
        bool flag=t2.match(s[index]);
        // cout<<s[index]<<"  "<<flag<<endl;
        if(flag==0){
            now->nxt[b[s[index]]]->ans=1;
        }
        else
        insert(s,index+1,len,now->nxt[b[s[index]]],t2);
        now->ans+=(now->nxt[b[s[index]]]->ans-tmp);
    }
}trie1,trie2;
int n;
char str[50001][51];
int main(){
    for(int i=0;i<26;i++) b['a'+i]=i+1;
    b['.']=27,b['/']=28;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",str[i]+1);
        trie2.insert(str[i]);
    }
    for(int i=1;i<=n;i++){
        trie2.remove(str[i]);
        trie1.insert(str[i],trie2);
        printf("%d\n",trie1.root->ans);
    }
    return 0;
}