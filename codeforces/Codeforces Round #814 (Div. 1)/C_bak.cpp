#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define endl '\n'
#define int long long
#define len(v) (int)(v.size())

using namespace std;

struct base {
    vector<int> a;
    multiset<int> s;
    
    void clear() {
        a.clear();
        s.clear();
    }
};

const int N = 2 * 1e5 + 1;

vector<bool> prime(N + 1, true);

vector<base> p(N + 1);

void genPrimes() {
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    set<int> id;
    
    id.insert(1);
    
    for (int i = 2; i < n; ++i) {
        if (prime[i] && n % i == 0) {
            id.insert(n / i);
        }
    }
    for(auto g:id) cout<<g<<"  ";
    puts("");
    vector<int> a(n);
    for (auto& it : a) {
        cin >> it;
    }
    
    int ans = -1;
    
    
    
    for (auto& g : id) {
        p[g].clear();
        
        p[g].a.resize(g);
        
        for (int k = 0; k < g; ++k) {
            
            for (int j = k; j < n; j += g) {
                p[g].a[k] += a[j] * g;
            }
            
            p[g].s.insert(p[g].a[k]);
        }
            
        ans = max(ans, *p[g].s.rbegin());
    }
    puts("");
    cout << ans << endl;

    while (q--) {
        int x, v;
        cin >> x >> v;
        
        x--;
        
        ans = -1;
        
        for (auto& g : id) {
            p[g].s.erase(p[g].s.find(p[g].a[x % g]));
            
            p[g].a[x % g] -= a[x] * g;
            p[g].a[x % g] += v * g;
            
            p[g].s.insert(p[g].a[x % g]);
            
            ans = max(ans, *p[g].s.rbegin());
        }
        
        cout << ans << endl;
        
        a[x] = v;
    }
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    
    genPrimes();
    
    int t; cin >> t;
    
    while (t--) {
        solve();
    }
}