#include <bits/stdc++.h>
using namespace std;
int a[150],b[150];
int main(){
    int T;
    cin>>T;
    while(T--){
        int max1=-1,max2=-1,n,m;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            max1=max(max1,x);
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            max2=max(max2,x);
        }
        if(max1==max2){
            puts("Alice\nBob");
        }
        if(max1>max2){
            puts("Alice\nAlice");
        }
        if(max2>max1){
            puts("Bob\nBob");
        }
    }
    return 0;
}