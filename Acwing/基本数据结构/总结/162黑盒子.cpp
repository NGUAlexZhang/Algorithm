#include <bits/stdc++.h>
using namespace std;
int a[35000];
int main(){
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int>>q2;
    int cnt=1;
    int n,m;
    scanf("%d%d",&n,&m);
    int p=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        while(p<=x){
            if(int(q1.size())<cnt||q1.top()>a[p]){
                q1.push(a[p]);
                if(q1.size()==cnt+1){
                    auto tmp=q1.top();
                    q1.pop();
                    q2.push(tmp);
                }
            }
            else{
                q2.push(a[p]);
            }
            p++;
        }
        printf("%d\n",q1.top());
        cnt++;
        if(q2.size()){
            auto tmp=q2.top();
            q1.push(tmp);
            q2.pop();
        }
    }
    return 0;
}