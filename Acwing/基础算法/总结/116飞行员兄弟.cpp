#include <bits/stdc++.h>
using namespace std;
char s[10][10];
void update(int x,int y){
    for(int i=1;i<=4;i++)
        if(s[x][i]=='+') s[x][i]='-';
        else s[x][i]='+';
    for(int i=1;i<=4;i++)
        if(s[i][y]=='-') s[i][y]='+';
        else s[i][y]='-';
    if(s[x][y]=='+') s[x][y]='-';
    else s[x][y]='+';
}
vector<pair<int,int>>sum,ans;
int step=1e9;
void dfs(int minn){
    if(minn>16){
        bool flag=1;
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            if(s[i][j]=='+') flag=0;
        if(flag&&sum.size()<step){
            ans=sum;
            step=sum.size();
        }
        return;
    }
    dfs(17);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if((i-1)*4+j<minn) continue;
            update(i,j);
            sum.push_back(make_pair(i,j));
            dfs((i-1)*4+j+1);
            sum.pop_back();
            update(i,j);
        }
    }
}
int main(){
    for(int i=1;i<=4;i++){
        scanf("%s",s[i]+1);
    }
    dfs(1);
    cout<<ans.size()<<endl;
    for(auto item:ans){
        cout<<item.first<<" "<<item.second<<endl;
    }
    return 0;
}