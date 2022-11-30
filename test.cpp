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

int inline getNext(int i) {
    return (i + str[i] - 'A' + 1) % n;
}

int main() {
    cin >> str;
    n = str.size();
    for (int i = 0; i < 1e6 + 5; i++)
        vis[i] = false;
    int i = 0, j = 1, len = 0, _i = 0, _j = 1;
    vis[0] = true, vis[1] = true;
    while (i < n && j < n && len < n) {
        int t = str[_i] - str[_j];
        if (!t) {
            _i = getNext(_i);
            _j = getNext(_j);
            len++;
        } else {
            if (t > 0) {
                int temp = i;
                while (temp != _i) {
                    vis[temp] = true;
                    temp = getNext(temp);
                }
                while (vis[i]) i++;
                vis[i] = true;
            } else {
                int temp = j;
                while (temp != _j) {
                    vis[temp] = true;
                    temp = getNext(temp);
                }
                while (vis[j]) j++;
                vis[j] = true;
            }
            _i = i, _j = j;
        }
    }
    cout << min(i, j) << endl;
    return 0;
}
