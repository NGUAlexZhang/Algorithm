#include <bits/stdc++.h>
using namespace std;
int a[2500000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        map<int,bool>m;
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]);m[a[i]]=1;}
        sort(a+1,a+1+n);
        int p=1;
        for(int i=1;i<=k;i++){
            while(m[p]) p+=2;
            a[++n]=p;
            m[p]=1;
        }
        p=0;
        for(int i=1;i<=k;i++){
            while(m[p]) p+=2;
            a[++n]=p;
            m[p]=1;
        }
        sort(a+1,a+1+n);
        a[0]=-1;
        int index=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=i-1){
                index=i;
                break;
            }
        }
        if(index==0) index=n+1;
        // cout<<a[index-1]<<endl;
        if((a[index-1]+1)%2){
            puts("Bob");
        }
        else puts("Alice");
    }
    return 0;
}