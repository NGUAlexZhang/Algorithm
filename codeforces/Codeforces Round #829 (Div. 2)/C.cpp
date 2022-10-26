#include <bits/stdc++.h>
using namespace std;
int a[250000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++){scanf("%d",&a[i]);sum+=a[i];}
        if(sum%2){
            puts("-1");
            continue;
        }
        vector<pair<int,int>>ans;
        for(int i=1;i<=n;i++){
            if(sum>0&&i!=n){
                if(a[i+1]==1) {ans.push_back(make_pair(i,i+1));i++;sum-=2;}
                else ans.push_back(make_pair(i,i));
            }
            else
            if(sum<0&&i!=n){
                if(a[i+1]==-1){ans.push_back(make_pair(i,i+1));i++;sum+=2;}
                else ans.push_back(make_pair(i,i));
            }
            else{
                ans.push_back(make_pair(i,i));
            }
        }
        printf("%d\n",ans.size());
        for(auto p:ans){
            printf("%d %d\n",p.first,p.second);
        }
    }
    return 0;
}