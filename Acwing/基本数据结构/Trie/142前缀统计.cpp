#include <bits/stdc++.h>
using namespace std;
struct Node{
    char c;
    int end;
    Node* nxt[40];
    Node(){
        end = 0;
        for(int i=0;i<40;i++) nxt[i]=nullptr;
    }
    Node(char c){
        this->c = c;
        for(int i=0;i<40;i++) nxt[i]=nullptr;
        end=0;
    }
};
char s[1500000];
Node* root = new Node;
void insert(){
    int len = strlen(s+1);
    Node* now = root;
    for(int i=1;i<=len;i++){
        if(now->nxt[s[i]-'a']!=nullptr){
            now = now->nxt[s[i]-'a'];
            continue;
        }
        now->nxt[s[i]-'a'] = new Node(s[i]);
        now = now->nxt[s[i]-'a'];
    }
    (now->end)++;
}
int getAns(){
    int ans=0;
    int len = strlen(s+1);
    Node* now = root;
    for(int i=1;i<=len;i++){
        if(now->nxt[s[i]-'a']!=nullptr){
            now = now->nxt[s[i]-'a'];
            ans+=now->end;
        }
        else break;
    }
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%s",s+1);
        insert();
    }
    for(int i=1;i<=m;i++){
        scanf("%s",s+1);
        printf("%d\n",getAns());
    }
    return 0;
}