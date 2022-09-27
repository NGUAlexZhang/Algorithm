#include <bits/stdc++.h>
using namespace std;
char s[10][800][800];
int wid[10];
int main(){
    int w=1;
    s[1][1][1]='X';
    for(int i=2;i<=7;i++){
        for(int j=1;j<=w;j++){
            for(int k=1;k<=w;k++) s[i][j][k]=s[i-1][j][k];
            for(int k=1;k<=w;k++) s[i][j][k+w]=' ';
            for(int k=1;k<=w;k++) s[i][j][k+2*w]=s[i-1][j][k];
        }
        for(int j=1;j<=w;j++){
            for(int k=1;k<=w;k++) s[i][j+w][k]=' ';
            for(int k=1;k<=w;k++) s[i][j+w][k+w]=s[i-1][j][k];
            for(int k=1;k<=w;k++) s[i][j+w][k+2*w]=' ';
        }
        for(int j=1;j<=w;j++){
            for(int k=1;k<=w;k++) s[i][j+2*w][k]=s[i-1][j][k];
            for(int k=1;k<=w;k++) s[i][j+2*w][k+w]=' ';
            for(int k=1;k<=w;k++) s[i][j+2*w][k+2*w]=s[i-1][j][k];
        }
        w*=3;
    }
    wid[0]=1;
    for(int i=1;i<=7;i++){
        wid[i]=wid[i-1]*3;
    }
    // cout<<s[1][1][1]<<endl;
    int n;
    while(cin>>n){
        if(n==-1) return 0;
        int len=wid[n-1];
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                printf("%c",s[n][i][j]);
            }
            puts("");
        }
        puts("-");
    }
    return 0;
}