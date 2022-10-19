#include <bits/stdc++.h>
using namespace std;
int ans[1500000],tot;
int main(){
    stack<int>st1,st2;
    ans[0]=-1e9-5;
    int T;
    scanf("%d",&T);
    int n=0;
    while(T--){
        string s;
        cin>>s;
        if(s=="I"){
            int x;
            scanf("%d",&x);
            st1.push(x);
            tot+=x;
            ans[n+1]=max(ans[n],tot);
            n++;
        }
        if(s=="L"){
            if(st1.empty()) continue;
            int x=st1.top();
            st2.push(x);
            n--;
            tot-=x;
            st1.pop();
        }
        if(s=="R"){
            if(st2.empty()) continue;
            int x=st2.top();
            st2.pop();
            st1.push(x);
            tot+=x;
            ans[n+1]=max(ans[n],tot);
            n++;
        }
        if(s=="D"){
            if(st1.empty()) continue;
            int x=st1.top();
            st1.pop();
            tot-=x;
            n--;
        }
        if(s=="Q"){
            int k;
            scanf("%d",&k);
            printf("%d\n",ans[k]);
        }
    }
    return 0;
}