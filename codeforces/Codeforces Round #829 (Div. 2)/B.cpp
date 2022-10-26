#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=(n/2);i>=1;i--){
            printf("%d %d ",i,i+(n/2));
        }
        if(n%2) printf("%d",n);
        puts("");
    }
    return 0;
}