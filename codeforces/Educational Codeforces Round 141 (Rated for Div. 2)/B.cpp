#include <bits/stdc++.h>
using namespace std;
int a[500*500+50];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int tmp=1;
        int now=n*n-1;
        a[1]=1;
        for(int i=2;i<=n*n;i++){
            a[i]=a[i-1]+tmp*now;
            now--;
            tmp*=-1;
        }
        for(int i=1;i<=n;i++){
            int st=(i-1)*n+1,ed=i*n;
            if(i%2){
                for(int j=st;j<=ed;j++) printf("%d ",a[j]);
            }
            else for(int j=ed;j>=st;j--) printf("%d ",a[j]);
            puts("");
        }
    }
    return 0;
}