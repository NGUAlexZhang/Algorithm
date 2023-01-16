#include <bits/stdc++.h>
using namespace std;
const double eps=1e-9;
struct Points{
    double x,y;
    Points(double _x,double _y){
        this->x=_x,this->y=_y;
    }
    Points(){
        x=y=0;
    }
    Points operator+(const Points& p){
        return Points(x+p.x,y+p.y);
    }
    Points operator-(const Points& p){
        return Points(x-p.x,y-p.y);
    }
    double operator*(const Points& p){
        return x*p.x+y*p.y;
    }
    double operator^(const Points& p){
        return x*p.y-y*p.x;
    }
    Points operator*(const double& k){
        return Points(x*k,y*k);
    }
    Points operator/(const double& k){
        return Points(x/k,y/k);
    }
    bool operator==(const Points& p){
        return fabs(x-p.x)<eps&&fabs(y-p.y)<eps;
    }
    double len(){
        return sqrt(x*x+y*y);
    }
}p[10],sp;
typedef Points Vec;
int sign(double x){
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    return 1;
}
void solve(){
    int index=0;
    for(int i=1;i<=3;i++){
        if(sp==p[i]){
            index=i;
            break;
        }
    }
    if(index!=0){
        Vec ans;
        for(int i=1;i<=3;i++){
            if(i!=index) ans=ans+p[i];
        }
        ans=ans/2;
        printf("%.9f %.9f\n",ans.x,ans.y);
        return;
    }
    index=0;
    Vec v1=p[2]-p[1],v2=p[3]-p[2],v3=p[1]-p[3];
    if(sign((sp-p[1])^(sp-p[2]))==0&&sign((sp-p[1])*(sp-p[2]))==-1) index=1;
    if(sign((sp-p[2])^(sp-p[3]))==0&&sign((sp-p[2])*(sp-p[3]))==-1) index=2;
    if(sign((sp-p[3])^(sp-p[1]))==0&&sign((sp-p[3])*(sp-p[1]))==-1) index=3;
    if(index==0){
        puts("-1");
        return;
    }
    if(index==1){
        double d1=(sp-p[1]).len(),d2=(sp-p[2]).len();
        // if(fabs(d1-d2)<eps){
        //     printf("%.9f %.9f\n",sp.x,sp.y);
        //     return;
        // }
        if(d1>d2){
            double h1=(p[2]-p[1])^(p[3]-p[1]);
            double h2=(sp-p[1])^(p[3]-p[1]);
            double rate=fabs(h1/h2);
            Vec t=(p[3]-p[1]);
            Points ans=p[1]+t*rate/2;
            printf("%.9f %.9f\n",ans.x,ans.y);
        }
        else{
            double h1=(p[1]-p[2])^(p[3]-p[2]);
            double h2=(sp-p[2])^(p[3]-p[2]);
            double rate=fabs(h1/h2);
            Points t=(p[3]-p[2]);
            Points ans=p[2]+t*rate/2;
            printf("%.9f %.9f\n",ans.x,ans.y);
        }
    }
    if(index==2){
        double d1=(sp-p[2]).len(),d2=(sp-p[3]).len();
        // if(fabs(d1-d2)<eps){
        //     printf("%.9f %.9f\n",sp.x,sp.y);
        //     return;
        // }
        if(d1>d2){
            double h1=(p[3]-p[2])^(p[1]-p[2]);
            double h2=(sp-p[2])^(p[1]-p[2]);
            double rate=fabs(h1/h2);
            Vec t=(p[1]-p[2]);
            Points ans=p[2]+t*rate/2;
            printf("%.9f %.9f\n",ans.x,ans.y);
        }
        else{
            double h1=(p[2]-p[3])^(p[1]-p[3]);
            double h2=(sp-p[3])^(p[1]-p[3]);
            double rate=fabs(h1/h2);
            Points t=(p[1]-p[3]);
            Points ans=p[3]+t*rate/2;
            printf("%.9f %.9f\n",ans.x,ans.y);
        }
    }
    if(index==3){
        double d1=(sp-p[3]).len(),d2=(sp-p[1]).len();
        // if(fabs(d1-d2)<eps){
        //     printf("%.9f %.9f\n",sp.x,sp.y);
        //     return;
        // }
        if(d1>d2){
            double h1=(p[1]-p[3])^(p[2]-p[3]);
            double h2=(sp-p[3])^(p[2]-p[3]);
            double rate=fabs(h1/h2);
            Vec t=(p[2]-p[3]);
            Points ans=p[3]+t*rate/2;
            printf("%.9f %.9f\n",ans.x,ans.y);
        }
        else{
            double h1=(p[3]-p[1])^(p[2]-p[1]);
            double h2=(sp-p[1])^(p[2]-p[1]);
            double rate=fabs(h1/h2);
            Points t=(p[2]-p[1]);
            Points ans=p[1]+t*rate/2;
            printf("%.9f %.9f\n",ans.x,ans.y);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=3;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        scanf("%lf%lf",&sp.x,&sp.y);
        solve();
    }
    return 0;
}