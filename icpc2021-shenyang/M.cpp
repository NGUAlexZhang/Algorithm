#include <bits/stdc++.h>
using namespace std;
char s[1500000];
int kmp[1500000];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    puts("1 1");
    int head=1,len=1;
    for(int i=2;i<=n;i++){
        while(len&&s[head+kmp[len]]<s[i]) head=head+(len-kmp[len]),len=kmp[len];
        if(len&&s[head+kmp[len]]==s[i]){
            len++;
            kmp[len]=kmp[len-1]+1;
        }
        else{
            kmp[++len]=0;
        }
        printf("%d %d\n",head,i);
    }
    return 0;
}