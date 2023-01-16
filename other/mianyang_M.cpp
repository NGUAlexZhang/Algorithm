#include <bits/stdc++.h>
using namespace std;
bool cmp(char A,char B){
    if(A==B) return 0;
    if(A!='P'&&B!='P')
        return A=='R';
    if(A!='R'&&B!='R')
        return A=='S';
    return A=='P';
}
char s[1500000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        vector<int>R,P,S;
        int len=strlen(s+1);
        for(int i=1;i<=len;i++){
            if(s[i]=='R') R.push_back(i);
            if(s[i]=='S') S.push_back(i);
            if(s[i]=='P') P.push_back(i);
        }
        for(int i=0;i<R.size()-1;i++){
            bool flag=0;
            for(int j=R[i]+1;j<R[i+1];j++){
                if(s[i]=='P') flag=1;
            }
            if(!flag)
            for(int j=R[i]+1;j<R[i+1];j++){
                s[i]='R';
            }
        }
        for(int i=0;i<P.size()-1;i++){
            bool flag=0;
            for(int j=P[i]+1;j<P[i+1];j++){
                if(s[i]=='S') flag=1;
            }
            if(!flag)
            for(int j=P[i]+1;j<P[i+1];j++){
                s[i]='P';
            }
        }
        for(int i=0;i<S.size()-1;i++){
            bool flag=0;
            for(int j=S[i]+1;j<S[i+1];j++){
                if(s[i]=='R') flag=1;
            }
            if(!flag)
            for(int j=S[i]+1;j<S[i+1];j++){
                s[i]='S';
            }
        }
        deque<char>st;
        st.push_back(s[1]);
        for(int i=2;i<=len;i++){
            if(s[i]==st.back()) continue;
            st.push_back(s[i]);
        }
        while(st.size()>1){
            if(st.size()>1)
            {
                auto now=st.front();
                st.pop_front();
                cout<<now<<"   "<<st.front()<<"  "<<cmp(now,st.front())<<endl;
                if(!cmp(now,st.front())) st.push_front(now);
            }
            if(st.size()>1)
            {
                auto now=st.back();
                st.pop_back();
                if(!cmp(now,st.back())) st.push_back(now);
            }
        }
        printf("%c\n",st.front());
    }
    return 0;
}