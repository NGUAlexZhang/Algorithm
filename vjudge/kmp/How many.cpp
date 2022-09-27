#include <bits/stdc++.h>
using namespace std;
int n;
char s[1500];
int main(){
    while(scanf("%d",&n)!=EOF){
        set<string> sum;
        while(n--){
            scanf("%s",s+1);
            int len=strlen(s+1);
            for(int i=1;i<=len;i++) s[i+len]=s[i];
            int index1=1,index2=2;
            while(index1<=len&&index2<=len){
                int p=0;
                while(p<len&&s[index1+p]==s[index2+p]) p++;
                if(p==len) break;
                if(s[index1+p]>s[index2+p]){
                    index1+=p+1;
                }
                else{
                    index2+=p+1;
                }
                if(index1==index2) index1++;
            }
            int st=min(index1,index2);
            string fin;
            for(int i=0;i<len;i++){
                fin+=s[st+i];
            }
            // cout<<st<<"   "<<fin<<endl;
            sum.insert(fin);
        }
        printf("%d\n",sum.size());
    }
    return 0;
}