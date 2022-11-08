#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
char s[1500][1500];
int a[1500],sum[1500];
int main(){
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){scanf("%c",&s[i][j]);getchar();}
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[j]=0;
            if(s[i][j]=='R') a[j]=0;
            else a[j]++;
        }
        // for(int j=1;j<=m;j++) cout<<a[j]<<" ";
        // puts("");
        stack<int>S;
        S.push(0);
        a[0]=-1,a[m+1]=0;
        for(int j=1;j<=m+1;j++){
            while(S.size()&&a[S.top()]>=a[j]){
                sum[S.top()]+=(j-S.top()-1)*a[S.top()];
                S.pop();
            }
            sum[j]+=(j-S.top())*a[j];
            S.push(j);
        }
        for(int j=1;j<=m;j++) ans=max(ans,sum[j]);
    }
    printf("%d",ans*3);
    return 0;
}