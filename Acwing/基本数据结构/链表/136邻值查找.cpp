#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    set<int>s1;
    set<int,greater<int>>s2;
    map<int,int>m;
    scanf("%d",&n);
    {
        int x;
        scanf("%d",&x);
        if(m[x]==0) m[x]=1;
        s1.insert(x);
        s2.insert(x);
    }
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        int ans1=2e9+3;
        if((s1.lower_bound(x))!=s1.end()){
            ans1=min(ans1,abs(x-*s1.lower_bound(x)));
        }
        if((s2.lower_bound(x))!=s2.end()){
            ans1=min(ans1,abs(x-*s2.lower_bound(x)));
        }
        // cout<<x<<" "<<minn<<" "<<maxx<<endl;
        printf("%d ",ans1);
        int loc=150000;
        if(m[x-ans1]) loc=m[x-ans1];
        else loc=m[x+ans1];
        
        printf("%d\n",loc);
        s1.insert(x),s2.insert(x);
        if(m[x]==0) m[x]=i;
    }
    return 0;
}