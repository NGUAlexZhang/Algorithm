#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    map<string,bool>ex;
    while(T--){
        int n;
        scanf("%d",&n);
        bool flag=0;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            if(ex[s]) continue;
            ex[s]=1;
            for(int i=0;i+2<s.size();i++){
                if(s[i]=='b'&&s[i+1]=='i'&&s[i+2]=='e'){
                    cout<<s<<endl;
                    flag=1;
                    break;
                }
            }
        }
        if(!flag) puts("Time to play Genshin Impact, Teacher Rice!");
    }
    return 0;
}