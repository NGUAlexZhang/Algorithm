#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define x first
#define y second
typedef pair<int,int> pii;
string s;
int n,hh,tt;
pii q[N];
void solve(){
    hh=0,tt=-1;
    cin >> s;
    for(int i=0;i<s.size();++i){
        if(s[i]!='B') continue;
        int l=i,r=i;
        while(l-1>=0 && s[l-1]=='A') l--;
        while(r+1<s.size() && s[r+1]=='C') r++;
        if(min(r-i,i-l)>0)
            q[++tt]=make_pair(min(r-i,i-l),(i+1)%2);
        cout<<(i+1)%2<<endl;
        i=r;
    }

    int ans=0,cnt=0; //答案和可以删B的次数
    for(int i=0;i<=tt;++i){
        if(cnt==0){
            if(q[i].y==0){
                if(q[i].x==1) ans++;
                else ans += 2, cnt ++;
            }
            else
                ans ++,cnt ++;
        }
        else{
            ans += min(q[i].x, (q[i].y==0)+cnt+1);
            cnt ++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}