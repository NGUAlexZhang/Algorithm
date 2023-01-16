#include <bits/stdc++.h>
using namespace std;
int n,m;
int get_min(int k,int l,int r,const vector<vector<vector<int>>>& st){
    int K=log2(r-l+1);
    return min(st[k][l][K],st[k][r-(1<<K)+1][K]);
}
bool check(int x,const vector<vector<int>>& a){
    vector<int>minn(n+3);
    // for(int i=1;i+x-1<=m;i++){
    //     int l=i,r=i+x-1;
    //     for(int j=1;j<=n;j++) minn[j]=get_min(j,l,r,st);
        // for(int j=1;j<=n;j++){
        //     int cnt=0;
        //     while(j+cnt<=n&&minn[j+cnt]>=x){
        //         cnt++;
        //         if(cnt==x) return true;
        //     }
        //     j=j+cnt;
        // }
    // }
    deque<int>q[n+3];
    for(int i=1;i<=n;i++){
        for(int j=1;j<x;j++){
            while(q[i].size()&&a[i][q[i].back()]>=a[i][j]) q[i].pop_back();
            q[i].push_back(j);
        }
    }
    for(int j=x;j<=m;j++){
        for(int i=1;i<=n;i++){
            while(q[i].size()&&j-x>=q[i].front()) q[i].pop_front();
            while(q[i].size()&&a[i][q[i].back()]>=a[i][j]) q[i].pop_back();
            q[i].push_back(j);
            // cout<<q[i].front()<<endl;
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
    // vector<vector<vector<int>>>st(n+1,vector<vector<int>>(m+1,vector<int>(21,0)));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    // for(int k=1;k<=20;k++){
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j+(1<<k)-1<=m;j++){
    //             st[i][j][k]=min(st[i][j][k-1],st[i][j+(1<<(k-1))][k-1]);
    //         }
    //     }
    // }
    int l=1,r=min(n,m);
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid,a)) l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",l-1);
}
int main(){
    // cout<<(1<<20);
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}