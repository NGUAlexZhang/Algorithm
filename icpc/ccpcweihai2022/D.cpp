#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 19;

int w[N], f[1 << N], vis[1 << N];
vector<pair<int,int>> v[N];  // v[i]：格子i作为跳板时，合法的跳跃前后格子
 
// 跳板格子，以及跳跃前后的两个格子
void add(int mid, int a, int b) 
{
    v[mid].push_back({a, b});
    v[mid].push_back({b, a});
}

int dfs(int state)
{
    if(vis[state]) return f[state];

    // Remove 
    for(int i = 0; i < N; ++ i) {
        if(!(state >> i & 1)) continue;
        f[state] = max(f[state], dfs(state - (1 << i)));
    }

    // Remove by jumping
    for(int i = 0; i < N; ++ i) {
        if(!(state >> i & 1)) continue;
        for(auto p : v[i]) {
            int a = p.first, b = p.second;
            if(!(state >> a & 1) || (state >> b & 1)) continue;
            f[state] = max(f[state], dfs(state - (1 << i) - (1 << a) + (1 << b)) + w[i]);
        }
    }

    vis[state] = 1;
    return f[state];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    for(int i = 0; i < N; ++ i) cin >> w[i];
    memset(f, -0x3f, sizeof f);
    f[0] = 0, vis[0] = 1;

    add(1, 0, 2);
    add(3, 0, 7);
    add(4, 0, 9), add(4, 1, 8), add(4, 3, 5);
    add(5, 1, 10), add(5, 2, 9), add(5, 4, 6);
    add(6, 2, 11);
    add(8, 3, 13), add(8, 4, 12), add(8, 7, 9);
    add(9, 4, 14), add(9, 5, 13), add(9, 8, 10);
    add(10, 5, 15), add(10, 6, 14), add(10, 9, 11);
    add(12, 7, 16);
    add(13, 8, 17), add(13, 9, 16), add(13, 12, 14);
    add(14, 9, 18), add(14, 10, 17), add(14, 13, 15);
    add(15, 11, 18);
    add(17, 16, 18);

    int test;
    cin >> test;
    while(test--) {
        string s, t;
        for(int i = 0; i < 5; ++ i) cin >> t, s += t;
        int state = 0;
        for(int i = 0; i < N; ++ i) {
            if(s[i] == '#') state += 1 << i;
        }
        cout << dfs(state) << endl;
    }

    return 0;
}