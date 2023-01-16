#include <bits/stdc++.h>
using namespace std;
int num1[10],num2[10];
int main(){
    map<string,int>S;
    set<string>ch;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            string name;
            cin>>name;
            ch.insert(name);
        }
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        string name;
        cin>>name;
        int id;
        cin>>id;
        if(ch.find(name)!=ch.end()){
            num1[id]++;
        }
        else{
            num2[id]++;
        }
    }
    int ans=0;
    bool flag=0;
    for(int i=1;i<=5;i++){
        while(num1[i]){
            for(int j=1;j<=5;j++){
                if(i==j) continue;
                if(num2[j]==0){
                    if(num1[j]==0){
                        flag=1;
                        break;
                    }
                    else{
                        num1[j]--;
                    }
                }else{
                    num2[j]--;
                }
            }
            if(!flag){
                num1[i]--;
                ans++;
            }
            else break;
        }
    }
    cout<<ans<<endl;
    return 0;
}