#include <bits/stdc++.h>
using namespace std;
int a[1500],d[1500];
int minn[1500],flag;
vector<int>G[1500];
void dfs(int now,int pre,int col){
    if(flag) return;
    if(d[now]&&d[now]!=col){
        flag=1;
        return;
    }
    d[now]=col;
    for(auto nxt:G[now]){
        if(nxt==pre) continue;
        dfs(nxt,now,3-col);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    minn[n+1]=1500;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--)
        minn[i]=min(minn[i+1],a[i]);
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++){
        if(a[i]<a[j]&&minn[j]<a[i]){
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!d[i]) dfs(i,0,1);
    }
    if(flag){
        printf("0");
        return 0;
    }
    stack<int>s1,s2;
    int tar=1;
    for(int i=1;i<=n;i++){
        if(d[i]==1){
            while((s1.size()&&s1.top()<=a[i])){
                while(s2.size()&&tar==s2.top()){
                    s2.pop();
                    printf("d ");
                    tar++;
                }
                printf("b ");
                s1.pop();
                tar++;
            }
            s1.push(a[i]);printf("a ");
        }
        else{
            while((s1.size()&&s1.top()==tar)){
                printf("b ");
                s1.pop();
                tar++;
            }
            while((s2.size()&&s2.top()<a[i])){
                printf("d ");
                s2.pop();
                tar++;
                while((s1.size()&&s1.top()==tar)){
                    printf("b ");
                    s1.pop();
                    tar++;
                }
            }
            s2.push(a[i]);printf("c ");
        }
    }
    while(s1.size()||s2.size()){
        if(s1.size()&&s1.top()==tar){
                printf("b ");
                s1.pop();
                tar++;
        }else{
            printf("d ");
            s2.pop();
            tar++;
        }
    }
    return 0;
}