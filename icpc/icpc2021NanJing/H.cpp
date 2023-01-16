#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
int main(){
    cin>>a>>b>>c;
    if(a>(b+c)){
        puts("YES");
        if(a==1&&b==0&&c==0){
            puts("0");
        }
        else cout<<(b+c)*2+1;
    }
    else{
        puts("NO");
    }
    return 0;
}