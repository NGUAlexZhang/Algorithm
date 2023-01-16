#include <bits/stdc++.h>
using namespace std;
struct Num{
    bool pos;
    int num;
    double fpr,tpr;
}a[1500000];
int n,prep[1500000],pren[1500000];
double TPR(int index){
    return (prep[n]-prep[index-1])*1.0/(prep[n]);
}
double FPR(int index){
    // if(index==2){
    //     cout<<(pren[n]-pren[index-1])*1.0/pren[n]<<endl;
    // }
    return (pren[n]-pren[index-1])*1.0/(pren[n]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        int num;
        cin>>s>>num;
        if(s=="-") a[i].pos=0;
        else a[i].pos=1;
        a[i].num=num;
    }
    sort(a+1,a+1+n,[](Num x,Num y){
        return x.num<y.num;
    });
    for(int i=1;i<=n;i++){
        prep[i]=prep[i-1],pren[i]=pren[i-1];
        if(a[i].pos) prep[i]++;
        else pren[i]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i].num==a[i-1].num){
            a[i].fpr=a[i-1].fpr;
            a[i].tpr=a[i-1].tpr;
            continue;
        }
        a[i].fpr=FPR(i);
        a[i].tpr=TPR(i);
        // cout<<a[i].num<<"  "<<a[i].tpr<<"  "<<a[i].fpr<<endl;
    }
    sort(a+1,a+1+n,[](Num x,Num y){
        return x.fpr<y.fpr;
    });
    double las=0,ans=0;
    for(int i=1;i<=n;i++){
        double maxn=a[i].tpr;
        while(i+1<=n&&a[i+1].fpr==a[i].fpr){
            i++;
            maxn=max(maxn,a[i].tpr);
        }
        // cout<<a[i].fpr<<"  "<<las<<"  "<<maxn<<endl;
        if(i==n) ans+=(1-a[i].fpr)*maxn;
        else
            ans+=(a[i+1].fpr-a[i].fpr)*maxn;
    }
    printf("%.9f",ans);
    return 0;
}