#include <bits/stdc++.h>
using namespace std;
char s[10];
int s1[10],s2[10];
void bfs(){

}
int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        for(int i=1;i<=4;i++) s1[i]=s[i]-'0';
        scanf("%s",s+1);
        for(int i=1;i<=4;i++) s2[i]=s[i]-'0';
        bfs();
    }
    return 0;
}