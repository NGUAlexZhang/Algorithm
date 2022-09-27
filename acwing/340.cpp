#include <bits/stdc++.h>
using namespace std;
int n,p,k,d[1500000];
bool used[1500000];
vector<pair<int,int>>G[1500000];
void bfs(){
    memset(d,0x7f,sizeof(d));
    d[1]=0;
    used[1]=1;
    queue<int>q;
    q.push(1);
    while(q.size()){
        int u=q.front();
        used[u]=0;
        q.pop();
        for(auto edge:G[u]){
            int to=edge.second,w=edge.first;
            if(d[to]>max(d[u],w)){
                d[to]=max(d[u],w);
                if(!used[to]){
                    used[to]=1;
                    q.push(to);
                }
            }
        }
    }
}
int main(){
    cin>>n>>p>>k;
    for(int i=1;i<=p;i++){
        int u,v,w;
        cin>>u>>v>>w;
        for(int j=0;j<=k;j++){
            if(j!=0){
                G[u+(j-1)*n].push_back(make_pair(0,j*n+v));
                G[v+(j-1)*n].push_back(make_pair(0,j*n+u));
            }
            G[u+j*n].push_back(make_pair(w,v+j*n));
            G[v+j*n].push_back(make_pair(w,u+j*n));
        }
    }
    bfs();
    int ans=d[0];
    for(int i=1;i<=k+1;i++){
        ans=min(ans,d[n*i]);
    }
    if(ans==d[0]) puts("-1");
    else
        cout<<ans;
    return 0;
}