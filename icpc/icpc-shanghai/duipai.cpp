//重点！数据比较器
#include<bits/stdc++.h>
using namespace std;
int main(){
    int i;
  for (i=1;;i++){
        printf("The result of No. %d Case is:  ",i);
        system("./data");
        system("./H_bak");
        system("./H");
        if (system("diff ans.out my.out")){
            printf("Wrong Answer\n");
            return 0;
        }
        else printf("Accepted\n");
    }
    return 0;
}