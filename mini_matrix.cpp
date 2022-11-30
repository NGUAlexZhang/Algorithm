#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[120][120];
ll sum[120][120];
int main(){
    for(int i=1;i<=100;i++) a[i][1]=i;
    for(int i=1;i<=100;i++){
        for(int j=2;j<=100;j++) a[i][j]=a[i][j-1]+2;
    }
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    }
    int ans=100*100+500;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            for(int k=i;k<=100;k++){
                for(int l=j;l<=100;l++){
                    ll num=sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1];
                    if(num==2022){
                        ans=min(ans,(k-i+1)*(l-j+1));
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}