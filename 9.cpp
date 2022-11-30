#include <bits/stdc++.h>
using namespace std;
char s[120][120];
int xl[120][120],xr[120][120];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        cin>>(s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==s[i-1][j-1]) xl[i][j]=xl[i-1][j-1]+1;
            else xl[i][j]=1;
            if(s[i][j]==s[i-1][j+1]) xr[i][j]=xr[i-1][j+1]+1;
            else xr[i][j]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tmp=ans;
            for(int k=1;i+k<=n&&j-k>=1;k++){
                //s[i+k][j],s[i][j-k];
                if(s[i+k][j]==s[i][j-k]&&s[i+k][j]==s[i][j]){
                    if(xl[i+k][j]>=k+1)
                        ans++;
                }
                else break;
            }
            for(int k=1;j+k<=m&&i+k<=m;k++){
                //s[i][j+k],s[i+k][j];
                if(s[i][j+k]==s[i+k][j]&&s[i+k][j]==s[i][j]){
                    if(xr[i+k][j]>=k+1)
                        ans++;
                }
                else break;
            }
            for(int k=1;j+k<=m&&i-k>=1;k++){
                //s[i-k][j],s[i][j+k];
                if(s[i][j+k]==s[i-k][j]&&s[i-k][j]==s[i][j]){
                    if(xl[i][j+k]>=k+1)
                        ans++;
                }
                else break;
            }
            for(int k=1;i-k>=1&&j-k>=1;k++){
                //s[i-k][j],s[i][j-k];
                if(s[i-k][j]==s[i][j-k]&&s[i-k][j]==s[i][j]){
                    if(xr[i][j-k]>=k+1)
                        ans++;
                }
                else break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}