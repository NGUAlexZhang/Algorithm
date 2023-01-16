#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x,index;
}a[550000];
int gr[550000];
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].x);
        a[i].index=i;
        gr[i]=i-1;
    }
    sort(a+1,a+1+n,[](const Node& A,const Node& B){
        return A.x<B.x;
    });
    int sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(sum+a[i].x>m) break;
        sum+=a[i].x;
        cnt++;
    }

    for(int i=cnt+1;i<=n;i++) gr[a[i].index]++;
    for(int i=cnt+1;i<=n;i++){
        if(gr[a[i].index]==cnt+1){
            if(sum-a[cnt].x+a[i].x<=m){
                gr[a[cnt].index]++;
                gr[a[i].index]--;
            }
            break;
        }
    }
    sort(gr+1,gr+1+n);
    reverse(gr+1,gr+1+n);
    int index=0;
    for(int i=1;i<=n;i++){
        if(cnt>=gr[i]){
            index=i;
            break;
        }
    }
    if(index==0) index=n+1;
    printf("%d\n",index);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}