#include <bits/stdc++.h>
using namespace std;
struct Num{
    int x,index;
}num[250000];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {num[i].index=i;scanf("%d",&num[i].x);}
    sort(num+1,num+1+n,[](Num n1,Num n2){
        if(n1.x==n2.x) return n1.index<n2.index;
        return n1.x<n2.x;
    });
    map<int,int>mxi,mii;
    for(int i=1;i<=n;i++){
        if(mxi[num[i].x]==0&&mii[num[i].x]==0){
            mxi[num[i].x]=mii[num[i].x]=num[i].index;
            continue;
        }
        mxi[num[i].x]=max(mxi[num[i].x],num[i].index);
        mii[num[i].x]=min(mii[num[i].x],num[i].index);
    }
    int las=mii[num[1].x],flag=0,ans=1;
    for(int i=2;i<=n;i++){
        if(num[i].x==num[i-1].x) continue;
        if(flag==0){
            if(las>mxi[num[i].x]) las=mii[num[i].x];
            else
                las=mxi[num[i].x],flag=1;
        }
        else{
            if(las<mii[num[i].x]) las=mxi[num[i].x];
            else
            las=mii[num[i].x],flag=0,ans++;
        }
        // printf("%d %d\n",i,ans);
        // if(i==4) printf("flag:%d %d\n",flag,ans);
    }
    // puts("");
    // for(int i=1;i<=n;i++) cout<<num[i].index<<" ";
    // puts("");
    printf("%d",ans);
    return 0;
}