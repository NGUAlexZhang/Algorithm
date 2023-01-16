#include <bits/stdc++.h>
using namespace std;
int x[150],y[150],z[150];
char ansc;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
    int ans=0,sum;
    map<pair<int,int>,bool>mp;
    sum=0;
    mp.clear();
    for(int i=1;i<=n;i++){
        if(mp[{y[i],z[i]}]==0){
            sum++;
        }
        mp[{y[i],z[i]}]=1;
    }
    if(sum>ans){
        ansc='X';
        ans=sum;
    }
    sum=0;
    mp.clear();
    for(int i=1;i<=n;i++){
        if(mp[{x[i],z[i]}]==0){
            sum++;
        }
        mp[{x[i],z[i]}]=1;
    }
    if(sum>ans){
        ansc='Y';
        ans=sum;
    }
    sum=0;
    mp.clear();
    for(int i=1;i<=n;i++){
        if(mp[{x[i],y[i]}]==0){
            sum++;
        }
        mp[{x[i],y[i]}]=1;
    }
    if(sum>ans){
        ansc='Z';
        ans=sum;
    }
    printf("%c",ansc);
    return 0;
}