#include <bits/stdc++.h>
using namespace std;
struct Node{  
    Node* nxt[2];
    Node(){
        nxt[0]=nxt[1]=nullptr;
    }
};
int s[100],ans=0;
Node* root = new Node();
void fill_s(int x){
    for(int i = 1;i <= 31;i++){
        s[i] = x%2;
        x /= 2;
    }
}
void insert(){
    Node* now = root;
    for(int i = 31;i >= 1;i--){
        if(now->nxt[s[i]]!=nullptr){
            now = now->nxt[s[i]];
        }
        else{
            now->nxt[s[i]] = new Node();
            now = now->nxt[s[i]];
        }
    }
}
void updateAns(){
    int sum=0;
    Node* now = root;
    for(int i = 31;i >= 1;i--){
        sum <<= 1;
        if(now->nxt[(!s[i])] != nullptr){
            sum += 1;
            now = now->nxt[!s[i]];
        }
        else{
            now = now->nxt[s[i]];
        }
    }
    ans = max(ans, sum);
}
int main(){
    int n;
    scanf("%d",&n);
    {
        int x;
        scanf("%d",&x);
        fill_s(x);
        insert();
    }
    for(int i = 2;i <= n;i++){
        int x;
        scanf("%d",&x);
        fill_s(x);
        updateAns();
        insert();       
    }
    printf("%d",ans);
    return 0;
}