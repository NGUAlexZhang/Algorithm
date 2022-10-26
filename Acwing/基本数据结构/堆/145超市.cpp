#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int>pii[15000];
void solve(){
    for(int i=1;i<=n;i++) scanf("%d%d",&pii[i].second,&pii[i].first);
    priority_queue<int,vector<int>,greater<int>>q;
    sort(pii+1,pii+1+n);
    for(int i=1;i<=n;i++){
        if(q.size()==pii[i].first&&pii[i].second>q.top()){
            q.pop();
            q.push(pii[i].second);
        }
        else{
            if(q.size()<pii[i].first){
                q.push(pii[i].second);
            }
        }
    }
    int ans=0;
    while(q.size()){
        ans+=q.top();
        q.pop();
    }
    printf("%d\n",ans);
}
int main(){
    while(scanf("%d",&n)!=EOF)
        solve();
    return 0;
}