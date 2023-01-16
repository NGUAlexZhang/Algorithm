#include <bits/stdc++.h>
using namespace std;
int a[200],b[200];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        vector<pair<int,int>>ans;
        for(int i=1;i<=n;i++){
            int index=i;
            for(int j=i+1;j<=n;j++){
                if(a[j]<a[index]){
                    index=j;
                }
                else
                if(a[j]==a[index]&&b[j]<b[index]) index=j;
            }
            if(index!=i){
                swap(a[index],a[i]);
                swap(b[index],b[i]);
                ans.push_back(make_pair(index,i));
            }
        }
        bool flag=1;
        for(int i=2;i<=n;i++)
            if(b[i]<b[i-1]) flag=0;
        if(flag){
            cout<<ans.size()<<endl;
            for(auto i:ans) cout<<i.first<<" "<<i.second<<endl;
        }
        else puts("-1");
    }
}