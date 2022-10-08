#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int N,C,x[1000],y[1000],d[1500];
int sum[1500][1500],cnt;
set<int>s;
map<int,int>rk;
bool check(int len){
    for(int x1=1,x2=1;x1<=cnt;x1++){
        while(d[x1]-d[x2]+1>len) x2++;
        for(int y1=1,y2=1;y1<=cnt;y1++){
            while(d[y1]-d[y2]+1>len) y2++;
            if(sum[x1][y1]-sum[x1][y2-1]-sum[x2-1][y1]+sum[x2-1][y2-1]>=C) {
                // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"  "<<sum[x1][y1]-sum[x1][y2-1]-sum[x2-1][y1]+sum[x2-1][y2-1]<<endl;    
                return true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&C,&N);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&x[i],&y[i]);
        s.insert(x[i]);
        s.insert(y[i]);
    }
    for(auto num:s){
        ++cnt;
        rk[num]=cnt;
        d[cnt]=num;
    }
    // for(int i=1;i<=cnt;i++){
    //     cout<<d[i]<<" ";
    // }
    // puts("");
    for(int i=1;i<=N;i++){
        int rkx=rk[x[i]],rky=rk[y[i]];
        sum[rkx][rky]++;
    }
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=cnt;j++)
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    }
    int l=1,r=10000;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d",r+1);
    return 0;
}