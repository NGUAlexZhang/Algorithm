#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
int main(){
    long long h,m,a;
    cin>>h>>m>>a;
    if(2*a==h*m){
        cout<<h*m;
        return 0;
    }
    long long g=__gcd(h-1,h*m);
    cout<<g*(2*(a/g)+1);
    return 0;
}
