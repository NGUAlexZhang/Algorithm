#include <bits/stdc++.h>
using namespace std;
int main(){
    double a,b,c=1.0/3;
    cin>>a>>b;
    for(int i=1;i<=10;i++){
        a*=c;
        b*=1.0;
        b/=3.0;
    }
    if(fabs(a-b)<1e-10){//

    }
    printf("%.10f %.10f",a,b);
    return 0;
}