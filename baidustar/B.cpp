#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
int v[MAXN+100],prime[MAXN+100],cnt;
bool is_prime[MAXN+500];
void solve(long long n){

    // long long n;
    // scanf("%lld",&n);
    long long tmp=sqrt(n);
    if(tmp*tmp!=n||is_prime[tmp]==0){
        // puts("NO");
        return;
    }
    // puts("YES");
    cnt++;
}
int main(){
    for(int i=2;i<=MAXN;i++){
        if(v[i]==0){
            v[i]=i;
            prime[++prime[0]]=i;
            is_prime[i]=1;
        }
        for(int j=1;j<=prime[0];j++){
            if(prime[j]>v[i]||prime[j]>MAXN/i) break;
            v[i*prime[j]]=prime[j];
        }
    }
    // for(int i=1;i<=100;i++) cout<<prime[i]<<"  ";
    // int T;
    // scanf("%d",&T);
    // // while(T--) solve();
    // for(long long i=10000000;i<=1000000000000;i++){
    //     solve(i);
    // }
    // cout<<cnt;
    for(int i=1;i<=100;i++){
        cout<<prime[prime[0]-i+1]<<" ";
    }
    return 0;
}