#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll h[150000],ans[150000];
int main(){
    while(cin>>n){
        if(n==0) return 0;
        stack<int>st;
        h[0]=-2;
        h[n+1]=-1;
        st.push(0);
        for(int i=1;i<=n;i++) {ans[i]=0;cin>>h[i];}
        for(int i=1;i<=n+1;i++){
            while(st.size()&&h[st.top()]>h[i]){
                ans[st.top()]+=(i-st.top()-1)*h[st.top()];
                st.pop();
            }
            ans[i]+=(i-st.top())*h[i];
            st.push(i);
        }
        ll maxn=0;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,ans[i]);
        }
        cout<<maxn<<endl;
    }
    return 0;
}