#include <bits/stdc++.h>
using namespace std;
int main(){
    srand((unsigned)time(0));
    int n=rand()%30+1;
    int t=rand()%2,k=rand()%60+1;
    for(int i=1;i<=n;i++){
        putchar('a'+(rand()%26));
    }
    puts("");
    cout<<t<<" "<<k;
    return 0;
}