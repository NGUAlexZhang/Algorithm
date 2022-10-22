#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>G[150000];
int s[1500];
struct Node{
    Node* nxt[2];
    Node(){
        nxt[0]=nxt[1]=nullptr;
    }
};
Node* root=new Node;
int ans=0;
void fill_s(int x){
    for(int i=1;i<=31;i++){
        s[i]=x%2;
        x/=2;
    }
}
void insert(){
    auto now=root;
    for(int i=31;i>=1;i--){
        if(now->nxt[s[i]]==nullptr) now->nxt[s[i]]=new Node();
        now=now->nxt[s[i]];
    }
}
void updateAns(){
    auto now=root;
    int sum=0;
    for(int i=31;i>=1;i--){
        sum<<=1;
        if(now->nxt[!s[i]]!=nullptr){
            sum++;
            now=now->nxt[!s[i]];
        }
        else{
            now=now->nxt[s[i]];
        }
    }
    ans=max(ans,sum);
}
void dfs(int now,int las,int sum){
    fill_s(sum);
    insert();
    updateAns();
    for(auto edge:G[now]){
        auto nxt=edge.first,val=edge.second;
        if(nxt==las) continue;
        dfs(nxt,now,sum^val);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    dfs(0,-1,0);
    printf("%d",ans);
    return 0;
}