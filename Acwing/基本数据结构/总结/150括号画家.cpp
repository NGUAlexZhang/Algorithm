#include <bits/stdc++.h>
using namespace std;
char s[150000];
int cnt[150000];
int main(){
    int ans=0,las=0;
    scanf("%s",s+1);
    int len=strlen(s+1);
    stack<int>S;
    map<char,char>m;
    m[')']='(',m[']']='[',m['}']='{';
    for(int i=1;i<=len;i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            S.push(i);
            continue;
        }
        if(S.empty()){
            continue;
        }
        if(m[s[i]]!=s[S.top()]){
            while(S.size()) S.pop();
        }
        else{
            cnt[i]=(i-S.top()+1)+cnt[S.top()-1];
            S.pop();
        }
    }
    for(int i=1;i<=len;i++) ans=max(ans,cnt[i]);
    printf("%d",ans);
    return 0;
}