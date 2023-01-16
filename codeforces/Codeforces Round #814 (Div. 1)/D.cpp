#include <bits/stdc++.h>
using namespace std;
int st[310000][25],a[310000],tree[310000][2],b[310000],flag;
vector<pair<int,int>>nodes;
int maxIndex(int l,int r){
    int k=log2(r-l+1);
    if(a[st[l][k]]>a[st[r-(1<<k)+1][k]]) return st[l][k];
    return st[r-(1<<k)+1][k];
}
int build_tree(int l,int r){
    if(l>r) return 0;
    int index=maxIndex(l,r);
    int ls=build_tree(l,index-1),rs=build_tree(index+1,r);
    tree[index][0]=ls,tree[index][1]=rs;
    return index;
}
int dfs(int now,int maxn){
    if(now==0) return 0;
    // cout<<now<<"   "<<b[now]<<endl;
    if(b[now]){
        if(b[now]>maxn) flag=1;
        maxn=min(maxn,b[now]);
    }
    int minn=b[now];
    if(tree[now][0]) minn=max(minn,dfs(tree[now][0],maxn));
    if(tree[now][1]) minn=max(minn,dfs(tree[now][1],maxn));
    if(!b[now]) nodes.push_back(make_pair(minn,maxn));
    return minn;
}
void solve(){
    nodes.clear();
    flag=0;
    set<int>S;
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        st[i][0]=i;
    }
    for(int i=1;i<25;i++){
        for(int j=1;j<=n;j++){
            int st1=j,st2=j+(1<<(i-1));
            if(st2>n) break;
            if(a[st[st1][i-1]]>a[st[st2][i-1]]) st[st1][i]=st[st1][i-1];
            else st[st1][i]=st[st2][i-1];
        }
    }
    build_tree(1,n);
    int num0=0;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]),num0+=(b[i]==0);
    for(int i=1;i<num0;i++){
        int x;
        scanf("%d",&x);
        S.insert(x);
    }
    int R=1e9,L=0;
    dfs(maxIndex(1,n),1e9);
    // cout<<nodes.size()<<endl;
    {
        auto T=S;
        sort(nodes.begin(),nodes.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second<b.second;
        });
        // cout<<nodes.size()<<endl;
        for(auto node:nodes){
            // cout<<node.first<<"  "<<node.second<<endl;
            auto it=T.lower_bound(node.first);
            if(it==T.end()||*it>node.second){
                if(R==1e9) R=node.second;
                else flag=1;
            }
            else T.erase(it);
        }
    }
    // cout<<flag<<endl;
    {
        auto T=S;
        sort(nodes.begin(),nodes.end(),[](pair<int,int> a,pair<int,int> b){
            return a.first>b.first;
        });
        for(auto node:nodes){
            // cout<<node.first<<" "<<node.second<<endl;
            auto it=T.upper_bound(node.second);
            if(it==T.begin()||*(--it)<node.first){
                if(L==0) L=node.first;
                else flag=1;
            }
            else
            T.erase(it);
        }
    }
    // cout<<L<<"   "<<R<<"  "<<flag<<endl;
    while(q--){
        int x;
        scanf("%d",&x);
        if(flag) puts("No");
        else{
            if(x<=R&&x>=L) puts("Yes");
            else puts("No");
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}