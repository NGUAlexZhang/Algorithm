#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int n,m;
int a[150000],l[150000],r[150000],del[150000];
void remove(int x){
    r[l[x]]=r[x];
    l[r[x]]=l[x];
    del[x]=1;
}
int main(){
    priority_queue<pii,vector<pii>,greater<pii>>q;
    scanf("%d%d",&n,&m);
    int k=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==0) continue;
        if(!k||1ll*a[k]*x<0) a[++k]=x;
        else a[k]+=x; 
    }
    int cnt=0,ans=0;
    for(int i=1;i<=k;i++){
        if(a[i]>0) ans+=a[i],cnt++;
        q.push({abs(a[i]),i});
        l[i]=i-1,r[i]=i+1;
    }
    while(cnt>m){
        auto u=q.top();
        q.pop();
        if(del[u.second]) continue;
        if(a[u.second]>0||(l[u.second]!=0&&r[u.second]!=k+1)){
            ans-=u.first;
            a[u.second]+=a[l[u.second]]+a[r[u.second]];
            if(l[u.second]!=0)
                remove(l[u.second]);
            if(r[u.second]!=k+1)
                remove(r[u.second]);
            q.push({abs(a[u.second]),u.second});
            cnt--;
        }
    }
    printf("%d",ans);
    return 0;
}