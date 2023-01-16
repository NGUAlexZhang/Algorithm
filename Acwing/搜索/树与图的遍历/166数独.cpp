#include <bits/stdc++.h>
using namespace std;
char s[100];
int a[12][12],r[12],c[12],nine[12],cnt[(1<<9)+5],mylog2[(1<<9)+5];
bool flag=0;
int lowbit(int x){
    return x&-x;
}
int getloc(int x,int y){
    return 3*((x-1)/3)+(y-1)/3+1;
}
void reversebit(int x,int y,int num){
    r[x]^=(1<<(num-1));
    c[y]^=(1<<(num-1));
    nine[getloc(x,y)]^=(1<<(num-1));
}
void dfs(int tot){
    if(flag) return;
    if(tot==0){
        for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++) printf("%d",a[i][j]);
        flag=1;
        return;
    }
    int minn=20,minx=0,miny=0;
    for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++){
        if(a[i][j]) continue;
        int num=r[i]&c[j]&nine[getloc(i,j)];
        if(cnt[num]<minn){
            minn=cnt[num];
            minx=i,miny=j;
        }
    }
    int num=r[minx]&c[miny]&nine[getloc(minx,miny)];
    while(num){
        int index=mylog2[lowbit(num)];
        a[minx][miny]=index;
        reversebit(minx,miny,index);
        dfs(tot-1);
        a[minx][miny]=0;
        reversebit(minx,miny,index);
        num-=lowbit(num);
    }
}
int main(){
    for(int i=0;i<(1<<9);i++){
        int num=i;
        while(num){
            cnt[i]++;
            num-=lowbit(num);
        }
    }
    for(int i=0;i<9;i++) mylog2[1<<i]=i+1;
    while(scanf("%s",s+1)){
        flag=0;
        if(s[1]=='e') return 0;
        for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++){
            if(s[(i-1)*9+j]=='.'){
                a[i][j]=0;
                continue;
            }
            a[i][j]=s[(i-1)*9+j]-'0';
        }
        int sum=0;
        for(int i=1;i<=9;i++) r[i]=c[i]=nine[i]=(1<<9)-1;
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++) 
                if(a[i][j])
                    reversebit(i,j,a[i][j]);
                else sum++;
        }
        dfs(sum);
        puts("");
    }
    return 0;
}