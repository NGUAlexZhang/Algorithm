#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
typedef long long ll;
const int maxn = 2e5+5;
const int mod = 1e9+7;
using namespace std;

ll sz[maxn], val[maxn];
int par[maxn], f[21][maxn], n, m, cnt;
vector<int> G[maxn];
vector< tuple<int, int, int> > es;

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void kruskal() {
	cnt = n;
	sort(es.begin(), es.end());

	for(int i = 0; i < m; i++) {
		auto [w, u, v] = es[i];
		u = find(u), v = find(v);
		if (u != v) {
			val[++ cnt] = w;
			par[cnt] = par[u] = par[v] = cnt;
			G[u].emplace_back(cnt);
			G[v].emplace_back(cnt);
			G[cnt].emplace_back(u);
			G[cnt].emplace_back(v);
		}
	}
}

void dfs0(int u, int fa) {
	f[0][u] = fa;
	for(int i = 1; i <= 20; i++) {
		f[i][u] = f[i - 1][f[i - 1][u]];
	}
	for(int v : G[u]) {
		if (v == fa) continue;
		dfs0(v, u);
		sz[u] += sz[v];
	}
}

int main() {

    freopen("data.in","r",stdin);
    freopen("ans.out","w",stdout);
	int q;
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++) par[i] = i;
	for(int i = 1; i <= n; i++) {
		cin >> sz[i];
	}

	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		es.emplace_back(w, u, v);
	}

	kruskal();
	dfs0(cnt, 0);
	val[0] = 1e18 + 7;

	while(q --) {
		int u;
		ll s;
		cin >> u >> s;
		ll cur = s + sz[u];
		while(u != cnt) {
			int x = u;
			for(int i = 20; i >= 0; i--) {
				if (val[f[i][u]] <= cur) u = f[i][u];
			}
			if (x == u) break;
            // cout<<u<<endl;
			cur = sz[u] + s;
		}
		cout << cur << '\n';
	}
    return 0;
}
