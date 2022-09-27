#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[20];

vector<pair<string,char>> getNext(string str,bool reverse=0){
    vector<pair<string,char>>ans;
    map<char,char>rc;
    rc['l']='r',rc['r']='l',rc['u']='d',rc['d']='u';
    int index=0;
    for(int i=1;i<=9;i++){
        if(str[i]=='x'){
            index=i;
            break;
        }
    }
    if(index-3>=1){
        string nxt=str;
        swap(nxt[index],nxt[index-3]);
        ans.push_back(make_pair(nxt,'d'));
    }
    if(index+3<=9){
        string nxt=str;
        swap(nxt[index],nxt[index+3]);
        ans.push_back(make_pair(nxt,'u'));
    }
    if(index%3!=1){
        string nxt=str;
        swap(nxt[index],nxt[index-1]);
        ans.push_back(make_pair(nxt,'r'));
    }
    if(index%3!=0){
        string nxt=str;
        swap(nxt[index],nxt[index+1]);
        ans.push_back(make_pair(nxt,'l'));
    }
    if(reverse)
        for(auto& item:ans)
            item.second=rc[item.second];
    return ans;
}
map<string,string>m;
void solve(){
    string str1="#12345678x";
    queue<string>q;
    m[str1]="#";
    q.push(str1);
    while(q.size()){
        string str=q.front();
        q.pop();
        auto nxts=getNext(str);
        for(auto nxt:nxts){
            string ns=nxt.first;
            char dir=nxt.second;
            if(m[ns]!="") continue;
            m[ns]=m[str]+dir;
            // cout<<m1[ns]<<endl;
            q.push(ns);
        }
    }
}
int main(){
    solve();
    cout<<m.size()<<endl;
    while(cin>>s[1]){
        for(int i=2;i<=9;i++) cin>>s[i];
        string str="#";
        for(int i=1;i<=9;i++) str+=s[i];
        // cout<<str<<endl;
        if(m[str].size()){
            for(int i=m[str].size()-1;i>0;i--) printf("%c",m[str][i]);
        }
        else printf("unsolvable");
        puts("");
    }
    return 0;
}