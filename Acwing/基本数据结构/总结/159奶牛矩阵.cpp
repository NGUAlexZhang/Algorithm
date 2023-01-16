#include <bits/stdc++.h>
using namespace std;
char s[15000][100];
int n,m,kmp[15000];
bool equal(char* s1,char* s2){
    for(int i=1;i<=m;i++){
        if(s1[i]!=s2[i]) return 0;
    }
    return 1;
}
bool cmp(int under,int c1,int c2){
    for(int i=1;i<=under;i++){
        if(s[i][c1]!=s[i][c2]) return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    // cout<<equal(s[1],s[4])<<endl;
    for(int i=2,j=0;i<=n;i++){
        while(j&&!equal(s[j+1],s[i])) j=kmp[j];
        if(equal(s[j+1],s[i])) j++;
        kmp[i]=j;
    }
    int height=n-kmp[n];
    // if(height!=1){
    //     printf("%d",height*m);
    //     return 0;
    // }
    kmp[1]=0;
    for(int i=2,j=0;i<=m;i++){
        while(j&&!cmp(height,j+1,i)) j=kmp[j];
        if(cmp(height,j+1,i)) j++;
        kmp[i]=j;
    }
    printf("%d",height*(m-kmp[m]));
    return 0;
}