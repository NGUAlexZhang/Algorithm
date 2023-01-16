#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll A,ll B){
    if(B==0) return A;
    return gcd(B,A%B);
}
int main(){
    ll H,M,A;
    cin>>H>>M>>A;
    if(2*A==H*M){
        cout<<H*M;
        return 0;
    }
    ll g=gcd(H-1,H*M);
    cout<<g*(2*(A/g)+1);
    return 0;
}