#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = 1e15;
ll a[150000];
int main(){
    ll n,m,q,u,v,t;
    scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&q,&u,&v,&t);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    double p=u*1.0/v;
    sort(a+1,a+1+n);
    queue<ll>q1,q2;
    ll len=0;
    int now=n;
    for(int i=1;i<=m;i++){
        ll num,num1,num2;
        if(now==0) num=-inf;
        else num=a[now];
        if(q1.empty()) num1=-inf;
        else num1=q1.front();
        if(q2.empty()) num2=-inf;
        else num2=q2.front();
        ll maxn=0;
        if(num>=num1&&num>=num2){
            maxn=num;
            now--;
        }
        else
        if(num1>=num&&num1>=num2){
            maxn=num1;
            q1.pop();
        }
        else
        if(num2>=num&&num2>=num1){
            maxn=num2;
            q2.pop();
        }
        maxn+=len;
        ll pp=maxn*p;
        ll qq=maxn-pp;
        len+=q;
        pp-=len,qq-=len;
        q1.push(pp),q2.push(qq);
        if(i%t==0) printf("%lld ",maxn);
    }
    puts("");
    for(int i=1;i<=n+m;i++){
        ll num,num1,num2;
        if(now==0) num=-inf;
        else num=a[now];
        if(q1.empty()) num1=-inf;
        else num1=q1.front();
        if(q2.empty()) num2=-inf;
        else num2=q2.front();
        ll maxn=0;
        if(num>=num1&&num>=num2){
            maxn=num;
            now--;
        }
        else
        if(num1>=num&&num1>=num2){
            maxn=num1;
            q1.pop();
        }
        else
        if(num2>=num&&num2>=num1){
            maxn=num2;
            q2.pop();
        }
        maxn+=len;
        if(i%t==0)
        printf("%lld ",maxn);
    }
    return 0;
}