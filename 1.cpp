#include <algorithm>
#include <iostream>
using namespace std;

struct Worker{
    int effect,speed;
};
bool cmp(Worker a,Worker b){
    return a.effect>b.effect;
}
int main(){
    int n,k;
    cin>>n>>k;
    Worker* workers=new Worker[n];
    int* maxn=new int[k+5];
    
    for(int i=0;i<n;i++){
        cin>>workers[i].speed;
    }
    for(int i=0;i<n;i++){
        cin>>workers[i].effect;
    }
    sort(workers,workers+n,cmp);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++)
            ans=max(ans,(maxn[j-1]+workers[i].speed)*workers[i].effect);
        for(int j=k;j>=1;j--){
            maxn[j]=max(maxn[j],maxn[j-1]+workers[i].speed);
        }
    }
    cout<<ans << endl;
    return 0;
}