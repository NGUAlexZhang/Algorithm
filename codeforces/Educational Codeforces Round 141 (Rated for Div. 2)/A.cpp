#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int index=0;
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        for(int i=1;i<n;i++){
            if(a[i]!=a[i+1]){
                index=i;
                continue;
            }
        }
        if(index==0){
            puts("No");
            continue;
        }
        puts("YES");
        printf("%d ",a[1]);
        for(int i=2;i<=n;i++){
            if(a[i]==a[1]) continue;
            printf("%d ",a[i]);
        }
        for(int i=2;i<=n;i++){
            if(a[i]!=a[1]) continue;
            printf("%d ",a[i]);
        }
        puts("");
    }
    return 0;
}