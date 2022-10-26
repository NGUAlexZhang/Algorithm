#include <bits/stdc++.h>
using namespace std;
char s[1500];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='Q') cnt++;
            else if(cnt) cnt--;
        }
        if(cnt||s[1]=='A') puts("No");
        else puts("Yes");
    }
    return 0;
}