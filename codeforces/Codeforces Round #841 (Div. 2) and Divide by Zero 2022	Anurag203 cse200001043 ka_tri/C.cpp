#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=2e5;
    int tmp=n;
    int cnt=0;
    while(tmp){
        cnt++;
        tmp>>=1;
    }
    n=(1<<cnt)-1;
    cout<<n<<endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        int num=sqrt(i);
        if(num*num==i){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}