#include <bits/stdc++.h>
using namespace std;
int n,cnt;
void solve(){
    ++cnt;
    printf("Scenario #%d\n",cnt);
    queue<int>q[1500],p;
    map<int,int>m;
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        for(int j=1;j<=num;j++){
            int x;
            scanf("%d",&x);
            m[x]=i;
        }
    }
    string s;
    while(cin>>s){
        if(s=="STOP") break;
        if(s=="ENQUEUE"){
            int x;
            scanf("%d",&x);
            if(q[m[x]].empty()) p.push(m[x]);
            q[m[x]].push(x);
        }
        if(s=="DEQUEUE"){
            printf("%d\n",q[p.front()].front());
            q[p.front()].pop();
            if(q[p.front()].empty()) p.pop();
        }
    }
    puts("");
}
int main(){
    while(scanf("%d",&n)){
        if(n==0) return 0;
        solve();
    }
    return 0;
}