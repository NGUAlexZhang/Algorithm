#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int ans1[1500000],ans2[1500000];
int main(){
    deque<pii>q1,q2;
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        while(q1.size()&&q1.front().first>=x){
            q1.pop_front();
        }
        while(q2.size()&&q2.front().first<=x){
            q2.pop_front();
        }
        q1.push_front({x,i});
        q2.push_front({x,i});
        while((i-q1.back().second)>=k){
            q1.pop_back();
        }
        while((i-q2.back().second)>=k){
            q2.pop_back();
        }
        ans1[i]=q1.back().first,ans2[i]=q2.back().first;
    }
    for(int i=k;i<=n;i++) printf("%d ",ans1[i]);
    puts("");
    for(int i=k;i<=n;i++) printf("%d ",ans2[i]);
    return 0;
}