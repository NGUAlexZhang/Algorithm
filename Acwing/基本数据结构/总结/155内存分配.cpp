#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
set<pii>tasks;
priority_queue<pii,vector<pii>,greater<pii>>end_time;
queue<pii>wait;
int len,ans;
bool give(pii task,int st){
    int lasend=-1;
    for(auto e:tasks){
        if(e.first-lasend-1>=task.second){
            tasks.insert({lasend+1,task.second});
            end_time.push({st+task.first,lasend+1});
            // cout<<lasend<<"  "<<task.second<<"  "<<st<<"   "<<task.first<<"    "<<st+task.first<<"   "<<e.first<<endl;
            return true;
        }
        lasend=e.first+e.second-1;
        // cout<<e.first<<"  "<<e.second<<"  "<<lasend<<endl;
    }
    return false;
}
void _free(int ti){
    // cout<<ti<<"  "<<end_time.size()<<endl;
    while(end_time.size()&&end_time.top().first<=ti){
        auto cl=end_time.top().first,st=end_time.top().second;
        // cout<<cl<<endl;
        while(end_time.size()&&end_time.top().first==cl){
            st=end_time.top().second;
            ans=max(ans,cl);
            auto it=tasks.lower_bound({st,0});
            // cout<<ti<<" "<<cl<<"  "<<st<<" "<<it->first<<"  "<<it->second<<endl;
            tasks.erase(it);
            end_time.pop();
        }
        while(wait.size()){
            if(give(wait.front(),cl)){
                wait.pop();
            }
            else break;
        }
    }
}
int main(){
    scanf("%d",&len);
    int cnt=0;
    // tasks.insert({-1,1});
    tasks.insert({len,1});
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        if(a==0&&b==0&&c==0) break;
        _free(a);
        if(!give({c,b},a)){
            wait.push({c,b});
            cnt++;
        }
    }
    a=2e9+5;
    _free(a);
    printf("%d\n%d",ans,cnt);
    // cout<<"\n"<<end_time.size();
    return 0;
}