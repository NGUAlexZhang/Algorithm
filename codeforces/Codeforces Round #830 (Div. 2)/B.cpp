#include <bits/stdc++.h>
using namespace std;
char s[250000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        bool ex=0,flag=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(ex==0){
                if(s[i]=='1') ex=1;
            }
            else{
                int x=s[i]-'0';
                x^=flag;
                if(x==0){
                    ans++;
                    flag^=1;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}