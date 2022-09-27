#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+500;
struct Points{
    double x,y;
    int id;
}p[2*MAXN];
double mindis=1e9;
bool cmp_x(const Points& p1,const Points& p2){
    return p1.x<p2.x||(p1.x==p2.x&&p1.y<p2.y);
}
bool cmp_y(const Points& p1,const Points& p2){
    return p1.y<p2.y;
}
void update_dis(const Points& p1,const Points& p2){
    if(p1.id==p2.id) return;
    double dist=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    if(dist<mindis) mindis=dist;
}
void rec(int l,int r){
    if(r-l<=3){
        for(int i=l;i<=r;i++){
            for(int j=i+1;j<=r;j++) update_dis(p[l],p[r]);
        }
        sort(p+l,p+r+1,cmp_y);
        return;
    }
    int mid=(l+r)>>1;
    double midx=p[mid].x;
    rec(l,mid);rec(mid+1,r);
    inplace_merge(p+l,p+mid+1,p+r+1,cmp_y);
    int tsz=0;
    static Points t[MAXN];
    for(int i=l;i<=r;i++){
        if(abs(midx-p[i].x)>=mindis) continue;
        for(int j=tsz;j>0&&p[i].y-t[j].y<mindis;j--){
            update_dis(p[i],t[j]);
        }
        t[++tsz]=p[i];
    }
}
void solve(){
    mindis=1e9;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        p[i].id=0;
    }
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[n+i].x,&p[n+i].y);
        p[n+i].id=1;
    }
    sort(p+1,p+1+n,cmp_x);
    rec(1,2*n);
    printf("%.3f\n",mindis);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}