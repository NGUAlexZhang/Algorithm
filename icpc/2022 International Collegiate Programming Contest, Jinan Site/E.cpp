#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        if(k%2==0){
            puts("Yes");
            continue;
        }
        if(n%k==0){
            if(n==k) puts("Yes");
            else
                puts("No");
            continue;
        }
        int e=(n/2),o=n/2;
        if(n%2) o++;
        int kk=min(e/(k/2),o/(k/2+(k%2)));
        e-=kk*(k/2),o-=kk*(k/2+k%2);
        if(o<=(k/2+(k%2))&&e<=(k/2)){
            puts("Yes");
            continue;
        }
        e=(n/2),o=n/2;
        if(n%2) o++;
        kk=min(o/(k/2),e/(k/2+(k%2)));
        o-=kk*(k/2),e-=kk*(k/2+k%2);
        if(e<=(k/2+(k%2))&&o<=(k/2)){
            puts("Yes");
            continue;
        }
        puts("No");
    }
    return 0;
}