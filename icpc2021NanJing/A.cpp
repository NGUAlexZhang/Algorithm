#include <bits/stdc++.h>
using namespace std;
vector<int>num;
int n,flag=0;
bool used[1500];
void dfs(int las,int maxn){
    if(num.size()==maxn){
        bool tmp=0;
        for(int i=0;i<maxn;i++){
            for(int j=0;j<maxn;j++){
                if(i==j) continue;
                if(num[i]%num[j]==0) tmp=1;
            }
        }
        if(tmp==0) flag=1;
        return;
    }
    for(int i=las+1;i<=n;i++){
        if(used[i]==true) continue;
        num.push_back(i);
        used[i]=1;
        dfs(i,maxn);
        num.pop_back();
        used[i]=0;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        // for(int i=2;i<=n;i++){
        //     flag=0;
        //     dfs(0,i);
        //     if(flag==0){
        //         cout<<i<<endl;
        //         break;
        //     }
        // }
        cout<<((n-2)/2+2+(n%2!=0))<<endl;
    }
    return 0;
}