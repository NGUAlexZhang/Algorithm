#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int a[100],n,b[100];
bool used[100];
void dfs(int dep,string str,int cnt){
    if(cnt==n){
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]) flag=1;
        }
        if(!flag){
            cout<<str<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(used[i]) continue;
        s.push(i);
        used[i]=1;
        dfs(dep+1,str+to_string(i),cnt);
        s.pop();
        used[i]=0;
    }
    if(s.size()){
        int x = s.top();
        s.pop();
        a[cnt+1]=x;
        dfs(dep+1,str,cnt+1);
        s.push(x);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) b[i]=i;
    dfs(0,"",0);
    return 0;
}