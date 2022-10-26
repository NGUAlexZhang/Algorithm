#include <bits/stdc++.h>
using namespace std;
int cnt[550000];
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    for(int i=1;i<x;i++){
        cnt[i+1]+=(cnt[i]/(i+1));
        cnt[i]%=(i+1);
        if(cnt[i]!=0){
            cout<<i<<endl;
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}