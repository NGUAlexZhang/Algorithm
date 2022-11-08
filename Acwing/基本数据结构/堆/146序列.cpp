#include <bits/stdc++.h>
using namespace std;
int a[2500],b[2500],c[2500],n,m;
void solve(){
    int p1=1,p2=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=1;i<=n;i++) {q.push(make_pair(a[i]+b[1],1));}
    int cnt=0;
    for(int i=1;i<=n;i++){
        auto t = q.top();
        c[++cnt] = t.first;
        q.pop();
        q.push(make_pair(t.first+b[t.second+1]-b[t.second],t.second+1));
    }
    for(int i=1;i<=n;i++){
        b[i]=c[i];
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++) b[i]=0;
        for(int j=1;j<=n;j++){
                scanf("%d",&b[j]);
            }
        for(int i=2;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[j]);
            }
            sort(a+1,a+1+n);
            solve();
        }
        for(int i=1;i<=n;i++) printf("%d ",b[i]); 
    }
    return 0;
}