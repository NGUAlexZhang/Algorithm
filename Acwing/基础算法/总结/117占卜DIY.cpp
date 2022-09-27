#include <bits/stdc++.h>
using namespace std;
int charToNum(char c){
    int num=-1;
    if(c>='0'&&c<='9'){
        if(c=='0') num=10;
        else num=c-'0';
    }
    if(c=='J') num=11;
    if(c=='Q') num=12;
    if(c=='K') num=13;
    if(c=='A') num=1;
    return num;
}
int cnt[20];
int main(){
    deque<char>q[15];
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            char x;
            scanf("%c",&x);
            getchar();
            q[i].push_back(x);
        }
    }
    while(q[13].size()){
        char c=q[13].front();
        q[13].pop_front();
        int num=charToNum(c);
        while(num!=13){
            cnt[num]++;
            c=q[num].back();
            q[num].pop_back();
            num=charToNum(c);
        }
    }
    int ans=0;
    for(int i=1;i<=13;i++){
        if(cnt[i]==4) ans++;
    }
    cout<<ans<<endl;
    return 0;
}