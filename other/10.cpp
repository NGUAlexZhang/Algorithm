#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <cstring>

using namespace std;

string str;
int n;
bool vis[1000005];
int fa[1000005];
int inline getNext(int i) {
    return (i + str[i] - 'A' + 1) % n;
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int main() {
    cin >> str;
    n = str.size();
    for (int i = 0; i < 1e6 + 5; i++)
        vis[i] = false;
    int i = 0, j = 1;
    vis[0] = true, vis[1] = true;
    while (i < n && j < n) {
        vis[i]=vis[j]=true;
        int curi=i,curj=j;
        map<int,int>mp;
        while(true){
            if(mp.find(curi)!=mp.end()&&mp[curi]==curj){
                int now=getNext(curj);
                vis[curj]=1;
                while(now!=curj){
                    vis[now]=1;
                    now=getNext(now);
                }
                now=getNext(j);
                while(now!=curj){
                    vis[now]=1;
                    now=getNext(now);
                }
                while(vis[j]) j++;
                break;
            }
            if(str[curi]==str[curj]){
                mp[curi]=curj;
                curi=getNext(curi);
                curj=getNext(curj);
                continue;
            }
            if(str[curi]<str[curj]){
                int now=getNext(j);
                while(now!=curj){
                    vis[now]=1;
                    now=getNext(now);
                }
                vis[curj]=1;
                while(vis[j]) j++;
                break;
            }
            else{
                int now=getNext(i);
                while(now!=curi){
                    vis[now]=1;
                    now=getNext(now);
                }
                vis[curi]=1;
                while(vis[i]) i++;
                break;
            }
        }
        if(i>j) swap(i,j);
    }
    cout << min(i, j) << endl;
    return 0;
}
