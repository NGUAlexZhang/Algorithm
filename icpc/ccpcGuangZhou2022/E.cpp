#include <bits/stdc++.h>
#define ll long long
using namespace std;
int maxn=500000;
int arr[550000];
int lowbit(int x){
    return x&-x;
}
void add(int x,int k){
    while(x<=maxn){
        arr[x]+=k;
        x+=lowbit(x);
    }
}
int getVal(int x){
    int sum=0;
    while(x>=1){
        sum+=arr[x];
        x-=lowbit(x);
    }
    return sum;
}
struct Node{
    int x,index,rank;
    ll ans;
}a[550000];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].x);
        a[i].index=i;
    }
    sort(a+1,a+1+n,[](Node x,Node y){
        return x.x<y.x; 
    });
    a[1].ans=0;
    ll sum=a[1].x;
    a[1].rank=1;
    for(int i=2;i<=n;i++){
        a[i].ans=a[i].x*1ll*(i-1)-sum;
        sum+=a[i].x;
        if(a[i].x==a[i-1].x) a[i].rank=a[i-1].rank;
        else
            a[i].rank=a[i-1].rank+1;
    }
    sort(a+1,a+1+n,[](Node x,Node y){
        return x.index<y.index;
    });
    for(int i=1;i<=n;i++){
        ll ans=a[i].ans+getVal(a[i].rank);
        if(ans>m-2) puts("-1");
        else printf("%lld\n",ans);
        add(a[i].rank,1);
    }
    return 0;
}