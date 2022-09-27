#include <bits/stdc++.h>
using namespace std;
int fa[500],n,las;
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int main(){
    srand(unsigned(time(0)));
    n=rand()%10+1;
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        int x=rand()%n+1;
        while(x==las){
            x=rand()%n+1;
        }
        cout<<x<<" ";
        las=x;
    }
    puts("");
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<n;i++){
        int x=rand()%n+1,y=rand()%n+1;
        while(find(x)==find(y)){
            x=rand()%n+1,y=rand()%n+1;
        }
        fa[find(x)]=find(y);
        cout<<x<<" "<<y<<endl;
    }

    return 0;
}