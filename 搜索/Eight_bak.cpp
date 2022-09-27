
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const char direct[4] = { 'd','u','r','l' };
const int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }, N = 362880;
vector<char> path[N];
bool visit[N];
const int aim = 46233;
const int n = 9;
//阶乘
const int fac[n] = { 1,1,2,6,24,120,720,5040,40320 };
//康托展开
int cantor(int s[]) {
    int result = 0, cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        cnt = 0;
        for (int j = i + 1; j < n; ++j) {
            if (s[i] > s[j])++cnt;
        }
        result += fac[n - 1 - i] * cnt;
    }
    return result;
}
void reverseCantor(int hash, int s[], int &space) {
    bool visited[n] = {};
    int temp;
    for (int i = 0; i < n; ++i) {
        temp = hash / fac[n - 1 - i];
        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                if (temp == 0) {
                    s[i] = j;
                    if (j == 0)space = i;
                    visited[j] = true;
                    break;
                }
                --temp;
            }
        }
        hash %= fac[n - 1 - i];
    }
}
//从终点逆向搜索，找到所有的可到达局面
void bfs() {
    queue<int> q;
    q.push(aim);
    visit[aim] = true;
    int state[n], space;
    while (!q.empty()) {
        int preHash = q.front();
        q.pop();
        reverseCantor(preHash, state, space);
        for (int i = 0; i < 4; ++i) {
            int tx = space / 3 + dir[i][0];
            int ty = space % 3 + dir[i][1];
            if (tx < 0 || tx>2 || ty < 0 || ty>2)continue;
            int tz = tx * 3 + ty;
            state[space] = state[tz];
            state[tz] = 0;
            int hash = cantor(state);
            if (!visit[hash]) {
                visit[hash] = true;
                q.push(hash);
                path[hash] = path[preHash];
                path[hash].push_back(direct[i]);
            }
            state[tz] = state[space];
            state[space] = 0;
        }
    }
}
int main() {
    bfs();
    char x;
    int a[n];
    while (~scanf(" %c", &x)) {
        if (x == 'x')a[0] = 0;
        else a[0] = x - '0';
        for (int i = 1; i < n; ++i) {
            scanf(" %c", &x);
            if (x == 'x')a[i] = 0;
            else a[i] = x - '0';
        }
        int hash = cantor(a);
        if (visit[hash]) {
            for (int i = path[hash].size() - 1; i >= 0; --i)printf("%c", path[hash][i]);
            printf("\n");
        }
        else printf("unsolvable\n");
    }
    return 0;
}