#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
void print_bin(int num){
    vector<int>ans;
    while(num){
        ans.push_back(num%2);
        num>>=1;
    }
    for(auto it=ans.rbegin();it!=ans.rend();it++){
        cout<<*it;
    }
}
int main(){
    int x;
    cout<<gcd(157,304);
    cin>>x;
    print_bin(x);
    puts("");
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(gcd(x,(i*x)^x)==1) {
            cout<<i<<" "<<(i*x)<<" "<<((i*x)^x)<<" ";
            print_bin(i);putchar(' ');
            print_bin((i*x));putchar(' ');
            print_bin((i*x)^x);
            puts("");
        }
    }
    // for(int i=1;i<=500;i++){
    //     if(gcd(i,x)==1){
    //         cout<<i<<" ";
    //         print_bin(i);
    //         puts("");
    //     }
    // }
    return 0;
}