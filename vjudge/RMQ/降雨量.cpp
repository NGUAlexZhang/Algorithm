#include <bits/stdc++.h>
using namespace std;
int n,m,y[55000],r[55000],st[55000][23];
int getMaxIndex(int ll,int rr){
    int k=log2(rr-ll+1);
    int index1=st[ll][k],index2=st[rr-(1<<k)+1][k];
    if(r[index1]>=r[index2]) return index1;
    return index2;
}
int main(){
    map<int,int>mp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&y[i],&r[i]);
        mp[y[i]]=i;
    }
    for(int i=1;i<=n;i++) st[i][0]=i;
    for(int j=1;j<23;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            if(r[st[i][j-1]]>=r[st[i+(1<<(j-1))][j-1]]) st[i][j]=st[i][j-1];
            else st[i][j]=st[i+(1<<(j-1))][j-1];
        }
    }
    scanf("%d",&m);
    while(m--){
        int X,Y;
        scanf("%d%d",&X,&Y);
        bool flag=0;
        if(!mp.count(X)||!mp.count(Y)){
            flag=1;
        }
        int index1=-1,index2=-1;
        int ll=1,rr=n;
        while(ll<=rr){
            int mid=(ll+rr)/2;
            if(y[mid]<=X) ll=mid+1;
            else rr=mid-1;
        }
        index1=ll-1;
        ll=1,rr=n;
        while(ll<=rr){
            int mid=(ll+rr)/2;
            if(y[mid]<=Y) ll=mid+1;
            else rr=mid-1;
        }
        index2=ll-1;
        cout<<index1<<"   "<<index2<<endl;
        if(index1==index2){
            puts("maybe");
            continue;
        }
        if(index1==0||index2==0||(index2-index1)!=(Y-X)){
            flag=1;
        }
        if(index1==0&&index2==0){
            puts("maybe");
            continue;
        }
        if(!flag){
            if(r[index1]>=r[index2]&&getMaxIndex(index1+1,index2)==index2){
                puts("true");
            }
            else puts("false");
        }
        else{
            if(y[index1]==X&&y[index2]==Y){
                if(r[index1]>=r[index2]&&getMaxIndex(index1+1,index2)==index2){
                    puts("maybe");
                }
                else puts("false");
                continue;
            }
            if(y[index1]!=X&&y[index2]!=Y){
                puts("maybe");
                continue;
            }
            if(y[index1]==X){
                int index=getMaxIndex(index1+1,index2);
                if(r[index1]>r[index]) puts("maybe");
                else puts("false");
            }
            else{
                int index=getMaxIndex(index1+1,index2);
                if(index!=index2) puts("false");
                else puts("maybe");
            }
        }
    }
    return 0;
}