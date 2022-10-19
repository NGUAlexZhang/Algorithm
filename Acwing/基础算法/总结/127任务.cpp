#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x,y;
    bool operator<(const Node& n1){
        if(this->x==n1.x) return this->y>n1.y;
        return this->x>n1.x;
    }
}tasks[150000],machines[150000];
int num[150];
int main(){
    long long sum=0;
    int n,m,cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&machines[i].x,&machines[i].y);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&tasks[i].x,&tasks[i].y);
    }
    sort(machines+1,machines+n+1);
    sort(tasks+1,tasks+m+1);
    multiset<int>ms;
    for(int i=1,j=1;i<=m;i++){
        while(j<=n&&machines[j].x>=tasks[i].x){
            num[machines[j].y]++;
            j++;
        }
        for(int k=tasks[i].y;k<=100;k++){
            if(num[k]){
                num[k]--;
                cnt++;
                sum+=500*tasks[i].x+2*tasks[i].y;
                break;
            }
        }
    }
    printf("%d %lld",cnt,sum);
    return 0;
}