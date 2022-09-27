#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int* head,* nxt,* to,ce,n,st,ed;
double* val,* ans;
bool* used;
void add(int u,int v){
    to[++ce]=v;nxt[ce]=head[u];head[u]=ce;
}
void spfa(){
    ans[st]=1;
    queue<int>q;
    q.push(st);
    used[st]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        used[u]=0;
        for(int i=head[u];i!=-1;i=nxt[i]){
            //cout<<i<<endl;
            int v=to[i];
            if(ans[u]*val[i]>ans[v]){
                ans[v]=ans[u]*val[i];
                if(!used[v]){
                    q.push(v);
                    used[v]=1;
                }
            }
        }
    }
}
int main(){
    cin>>n>>st>>ed;
    head=new int[n];
    nxt=new int[2*n+5];
    to=new int[2*n+5];
    val=new double[2*n+5];
    ans=new double[n];
    used=new bool[n];
    memset(nxt,-1,sizeof(nxt));
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    int ce=0;
    for(int i=0;i<n;i++){
        double w;
        cin>>w;
        val[++ce]=w;
        val[++ce]=w;
    }
    spfa();
    cout<<ans[ed];
    return 0;
}