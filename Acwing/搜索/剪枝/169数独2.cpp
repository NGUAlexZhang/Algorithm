#include <bits/stdc++.h>
using namespace std;
int a[20][20],bstate2[16*16+50][20][20],bstate[16*16+50][20][20],ba[16*16+50][20][20],cnt[(1<<16)+50],mylog2[(1<<16)+50],state[20][20];
char s[20];
int lowbit(int x){
    return x&-x;
}
void draw(int x,int y,int num){
    a[x][y]=num;
    for(int i=1;i<=16;i++){
        state[i][y]&=(~(1<<(num-1)));
        state[x][i]&=(~(1<<(num-1)));
    }
    int sx=(x-1)/4*4,sy=(y-1)/4*4;
    for(int i=1;i<=4;i++)
    for(int j=1;j<=4;j++)
        state[sx+i][sy+j]&=(~(1<<(num-1)));
    state[x][y]=1<<(num-1);
}
bool dfs(int step){
    if(step==0) return true;
    int tstep=step;
    memcpy(bstate[tstep],state,sizeof(state));
    memcpy(ba[tstep],a,sizeof(a));
    for(int i=1;i<=16;i++)
    for(int j=1;j<=16;j++){
        if(a[i][j]==0){
            if(state[i][j]==0){
                memcpy(state,bstate[tstep],sizeof(state));
                memcpy(a,ba[tstep],sizeof(a));
                return false;
            }
            if(cnt[state[i][j]]==1){
                draw(i,j,mylog2[state[i][j]]);
                --step;
            }
        }
    }
    for(int i=1;i<=16;i++){
        int sor=0,sand=(1<<16)-1,drawn=0;
        for(int j=1;j<=16;j++){
            sand&=~(sor&state[i][j]);
            sor|=state[i][j];
            if(a[i][j]!=0) drawn|=state[i][j];
        }
        if(sor!=(1<<16)-1){
            memcpy(state,bstate[tstep],sizeof(state));
            memcpy(a,ba[tstep],sizeof(a));
            return false;
        }
        while(sand){
            int las=lowbit(sand);
            if(!(drawn&las)){
                for(int j=1;j<=16;j++){
                    if(state[i][j]&las){
                        draw(i,j,mylog2[las]);
                        --step;
                        break;
                    }
                }
            }
            sand-=las;
        }
    }
    for(int j=1;j<=16;j++){
        int sor=0,sand=(1<<16)-1,drawn=0;
        for(int i=1;i<=16;i++){
            sand&=~(sor&state[i][j]);
            sor|=state[i][j];
            if(a[i][j]!=0) drawn|=state[i][j];
        }
        if(sor!=(1<<16)-1){
            memcpy(state,bstate[tstep],sizeof(state));
            memcpy(a,ba[tstep],sizeof(a));
            return false;
        }
        while(sand){
            int las=lowbit(sand);
            if(!(drawn&las)){
                for(int i=1;i<=16;i++){
                    if(state[i][j]&las){
                        draw(i,j,mylog2[las]);
                        --step;
                        break;
                    }
                }
            }
            sand-=las;
        }
    }
    for(int sx=0;sx<=12;sx+=4)
    for(int sy=0;sy<=12;sy+=4){
        int sor=0,sand=(1<<16)-1,drawn=0;
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++){
            sand&=~(sor&state[sx+i][sy+j]);
            sor|=state[sx+i][sy+j];
            if(a[sx+i][sy+j]!=0) drawn|=state[sx+i][sy+j];
        }
        if(sor!=(1<<16)-1){
            memcpy(state,bstate[tstep],sizeof(state));
            memcpy(a,ba[tstep],sizeof(a));
            return false;
        }
        while(sand){
            int las=lowbit(sand);
            if(!(drawn&las)){
                for(int i=1;i<=4;i++)
                for(int j=1;j<=4;j++){
                    if(state[sx+i][sy+j]&las){
                        draw(sx+i,sy+j,mylog2[las]);
                        step--;
                        break;
                    }
                }
            }
            sand-=las;
        }
    }
    if(step==0) return true;
    int x,y,minn=100;
    for(int i=1;i<=16;i++)
    for(int j=1;j<=16;j++){
        if(a[i][j]==0&&cnt[state[i][j]]<minn){
            x=i,y=j,minn=cnt[state[i][j]];
        }
    }
    // cout<<x<<"   "<<y<<endl;
    memcpy(bstate2[tstep],state,sizeof(state));
    for(int i=state[x][y];i;i-=lowbit(i)){
        memcpy(state,bstate2[tstep],sizeof(state));
        draw(x,y,mylog2[lowbit(i)]);
        if(dfs(step-1)) return true;
    }
    memcpy(state,bstate[tstep],sizeof(state));
    memcpy(a,ba[tstep],sizeof(a));
    return false;
}
int main(){
    for(int i=0;i<(1<<16);i++){
        auto num=i;
        while(num){
            cnt[i]++;
            num-=lowbit(num);
        }
    }
    for(int i=0;i<16;i++) mylog2[1<<i]=i+1;
    while(scanf("%s",s+1)!=EOF){
        int step=0;
        for(int i=1;i<=16;i++) a[1][i]=(s[i]=='-')?0:(s[i]-'A'+1);
        for(int i=2;i<=16;i++){
            scanf("%s",s+1);
            for(int j=1;j<=16;j++) a[i][j]=(s[j]=='-')?0:(s[j]-'A'+1);
        }
        for(int i=1;i<=16;i++)
        for(int j=1;j<=16;j++) state[i][j]=(1<<16)-1;
        for(int i=1;i<=16;i++){
            for(int j=1;j<=16;j++){
                if(a[i][j]==0) step++;
                else draw(i,j,a[i][j]);
            }
        }
        dfs(step);
        for(int i=1;i<=16;i++){
            for(int j=1;j<=16;j++){
                printf("%c",a[i][j]+'A'-1);
            }
            puts("");
        }
        puts("");
    }
    
    return 0;
}