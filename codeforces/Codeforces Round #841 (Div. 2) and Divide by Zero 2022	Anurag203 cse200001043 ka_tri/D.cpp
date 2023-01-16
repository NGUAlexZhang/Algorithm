#include <bits/stdc++.h>
using namespace std;
int n,m;
bool check(int x,const const vector<vector<int>>& a){
    vector<int>minn(n+3);
    deque<int>q[n+3];
    for(int i=1;i<=n;i++){
        for(int j=1;j<x;j++){
            while(q[i].size()&&a[i][q[i].back()]>=a[i][j]) q[i].pop_back();
            q[i].push_back(j);
        }
    }
    for(int j=x;j<=m;j++){
        for(int i=1;i<=n;j++){
            while(q[i].size()&&j-x>=q[i].front()) q[i].pop_front();
            while(q[i].size()&&a[i][q[i].back()]>=a[i][j]) q[i].pop_back();
            q[i].push_back(j);
            minn[i]=a[i][q[i].front()];
        }
        for(int i=1;i<=n;i++){
            int cnt=0;
            while(i+cnt<=n&&minn[i+cnt]>=x){
                cnt++;
                if(cnt==x) return true;
            }
            i=i+cnt;
        }
    }
    return false;
}
void solve(){
    scanf("%d%d",&n,&m);
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int l=1,r=min(n,m);
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid,a)) l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",l-1);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}