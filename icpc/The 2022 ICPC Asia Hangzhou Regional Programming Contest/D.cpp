#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    sum/=(n+1);
    printf("%.10f ",2*sum);
    for(int i=2;i<=n;i++) 
        printf("%.10f ",sum);
    return 0;
}