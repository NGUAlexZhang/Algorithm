#include <bits/stdc++.h>
using namespace std;
char s[1500][1500];
bool used[1500][1500];
int n,m;
bool is1(int x,int y){
    if(x+2>n||y>m) return false;
    bool flag=1;
    for(int i=0;i<=2;i++){
        if(s[x+i][y]=='.') flag=0;
    }
    return flag;
}
bool is0(int x,int y){
    if(x+2>n||y+2>m) return false;
    bool flag=1;
    for(int i=0;i<=2;i++){
        if(s[x+i][y]=='.'||s[x+i][y+2]=='.') flag=0;
    }
    for(int i=0;i<=2;i++){
        if(s[x][y+i]=='.'||s[x+2][y+i]=='.') flag=0;
    }
    return flag&&(s[x+1][y+1]=='.');
}
bool is8(int x,int y){
    if(x+2>n||y+4>m) return false;
    bool flag=1;
    for(int i=0;i<=2;i++){
        if(s[x+i][y]=='.'||s[x+i][y+4]=='.') flag=0;
    }
    for(int i=0;i<=4;i++){
        if(s[x][y+i]=='.'||s[x+2][y+i]=='.') flag=0;
    }
    return flag&&(s[x+1][y+1]=='.')&&(s[x+1][y+2]=='#')&&(s[x+1][y+3]=='.');
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    int ans1=0,ans2=0,ans3=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(is8(i,j)){
                ans3++;
                while(j+2<=m&&is8(i,j+2)){
                    ans3++;
                    j+=2;
                }
                j+=4;
                continue;
            }
            if(is0(i,j)){
                ans2++;
                j+=2;
                continue;
            }
            if(is1(i,j)){
                // cout<<i<<" "<<j<<endl;
                ans1++;
                continue;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3;
    return 0;
}