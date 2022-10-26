#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x;
    int index;
    bool operator<(Node node) const{
        return x>(node.x);
    }
    Node(int x,int index){
        this->x=x,this->index=index;
    }
};
int p[2500],a[2500][1500];
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        sort(a[i]+1,a[i]+1+m);
    int tot=0;
    for(int i=1;i<=n;i++) tot+=a[i][1],p[i]=1;
    priority_queue<Node>q;
    for(int i=1;i<=n;i++){
        if(p[i]<m) q.push(Node(a[i][p[i]+1]-a[i][p[i]],i));
    }
    int cnt=1;
    if(n*m!=0)
        printf("%d ",tot);
    while(q.size()){
        auto node = q.top();
        q.pop();
        tot+=node.x;
        p[node.index]++;
        if(p[node.index]<m){
            q.push(Node(a[node.index][p[node.index]+1]-a[node.index][p[node.index]],node.index));
        }
        printf("%d ",tot);
        cnt++;
        if(cnt==m) break;
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}