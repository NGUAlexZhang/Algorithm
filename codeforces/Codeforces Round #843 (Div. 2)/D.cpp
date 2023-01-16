#include <bits/stdc++.h>
using namespace std;
const int MAXN=3e5;
bool is_prime[MAXN+50],vis[MAXN+50],used[MAXN+50];
int primes[MAXN+50],n,pre[MAXN+50];
vector<int>s[MAXN+50],in[MAXN+50];
void process(int x,int index){
    for(int i=1;i<=primes[0]&&primes[i]*primes[i]<=x;i++){
        if(x%primes[i]) continue;
        s[primes[i]].push_back(index);
        in[index].push_back(primes[i]);
        while(x%primes[i]==0) x/=primes[i];
    }
    if(x!=1){
        s[x].push_back(index);
        in[index].push_back(x);
    }
}
int main(){
    for(int i=2;i<=MAXN;i++) is_prime[i]=1;
    for(int i=2;i<=MAXN;i++){
        if(is_prime[i])
            primes[++primes[0]]=i;
        for(int j=1;j<=primes[0]&&i*primes[j]<=MAXN;j++){
            is_prime[i*primes[j]]=0;
            if(i%primes[j]==0) break;
        }
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        process(x,i);
    }
    int st,ed;
    scanf("%d%d",&st,&ed);
    queue<int>q;
    q.push(st);
    vis[st]=1;
    while(q.size()){
        int u=q.front();
        if(u==ed) break;
        q.pop();
        for(auto it1:in[u]){
            if(used[it1]) continue;
            used[it1]=1;
            for(auto it2:s[it1]){
                if(vis[it2]) continue;
                pre[it2]=u;
                vis[it2]=1;
                q.push(it2);
            }
        }
    }
    if(vis[ed]==0){
        puts("-1");
        return 0;
    }
    int now=ed;
    vector<int>ans;
    while(now!=st){
        ans.push_back(now);
        now=pre[now];
    }
    reverse(ans.begin(),ans.end());
    printf("%d\n",1+int(ans.size()));
    printf("%d ",st);
    for(auto it:ans) printf("%d ",it);
    return 0;
}