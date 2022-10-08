#include <bits/stdc++.h>
using namespace std;
struct Point{
    int x, y;
}points[150000];
int n;
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    sort(points + 1, points + n + 1, [](Point& p1, Point& p2){
        return p1.y < p2.y;
    });
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += abs(points[i].y - points[(n + 1) / 2].y);
    }
    sort(points + 1, points + n + 1, [](Point& p1, Point& p2){
        return p1.x < p2.x;
    });
    for(int i = 1; i <= n; i++){
        points[i].x -= i;
    }
    sort(points + 1, points + n + 1, [](Point& p1, Point& p2){
        return p1.x < p2.x;
    });
    for(int i = 1; i <= n; i++){
        ans += abs(points[i].x - points[(n + 1) / 2].x);
    }
    printf("%d",ans);
    return 0;
}