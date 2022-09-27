#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("data.in","w",stdout);
    srand(unsigned(time(0)));
    int n=rand()%5+2;
    int m=rand()%5+1,q=5;
    cout<<n<<" "<<m<<" "<<q<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%10000+1<<" ";
    }
    puts("");
    for(int i=1;i<=m;i++){
        int num1=rand()%n+1;
        int num2=rand()%n+1;
        while(num2==num1){
            num2=rand()%n+1;
        }
        cout<<num1<<" "<<num2<<" "<<rand()%1000+900000000<<endl;
    }
    while(q--)
    cout<<rand()%n+1<<" "<<rand()%1000+900000000<<endl;
    return 0;
}

/*
8 6 1
285 9548 5354 3414 7431 5442 702 228 
1 7 900000727
4 2 900000017
1 3 900000761
2 1 900000803
5 1 900000679
1 8 900000572
1 900000064

*/

/*
3 5 1
5145 139 4213 
1 3 900000351
3 1 900000559
2 1 900000272
1 2 900000383
3 2 900000437
2 900000055
*/