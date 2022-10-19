#include <bits/stdc++.h>
using namespace std;
int a[200],b[200];
template<typename T>
int test(){
    list<T> k;
    typename list<T>::iterator it= k.begin();
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,cnta=0,cntb=0,flag=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++){
            if(a[i]==1) cnta++;
            if(b[i]==1) cntb++;
        }
        int ans=abs(cnta-cntb);
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){
                if(cnta<=cntb&&a[i]==1) {ans++;break;}
                if(cnta>=cntb&&a[i]==0) {ans++;break;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}