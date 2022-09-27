#include <bits/stdc++.h>
using namespace std;
int a[250000];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        cin>>m;
        int p=0;
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            p+=x;
            p%=n;
        }
        cout<<a[p]<<endl;
    }
    return 0;
}