 #include <iostream>
 #include <cstring>
 #include <algorithm>
 #include <set>

 using namespace std;
 #define int long long
 const int N = 2e3 + 10, M = 2 * N, mod = 1e9 + 7;
 int n, m;
 int a[N], b[N], c[N], p[N];
 int h[N], e[M], ne[M], idx;
 int fa[N], depth[N], sz[N], cur;
 int f[N][N], g[N][N], ans[N];
 
 void add(int a, int b) {
     e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
 }
 
 int qmi(int a, int k) {
     int res = 1;
     while(k) {
         if(k & 1) res = res * a % mod;
         a = a * a % mod;
         k >>= 1;
     }
     return res;
 }
 
 int inv(int x) {
     return qmi(x, mod - 2);
 }
 
 void dfs(int u, int father) {
     fa[u] = father, sz[u] = 1;
     depth[u] = depth[father] + 1;
     static int tmp1[N], tmp2[N];
     f[u][1] = p[u];
     g[u][1] = a[u] * inv(cur) % mod;
     f[u][0] = (1 - p[u]) + mod;
     g[u][0] = (1 - p[u]) + mod;
     for(int i = h[u]; ~i ; i = ne[i]) {
         int j = e[i];
         if(j == father) continue;
         dfs(j, u);
         for(int k = 0; k <= sz[u] + sz[j]; k++ ) tmp1[k] = tmp2[k] = 0;
         for(int k = 1; k <= sz[u]; k++ ) 
             for(int l = 0; l <= sz[j]; l++ ) {
                 tmp1[k + l] = (tmp1[k + l] + f[u][k] * f[j][l] % mod) % mod;
                 tmp2[k + l] = (tmp2[k + l] + g[u][k] * f[j][l] % mod) % mod;
                 if(l) tmp2[k + l] = (tmp2[k + l] + f[u][k] * g[j][l] % mod) % mod;
             }
         for(int k = 1; k <= sz[u] + sz[j]; k++ ) {
             f[u][k] = tmp1[k];
             g[u][k] = tmp2[k];
         }
         sz[u] += sz[j];
     }
 
 }
 
 signed main() {
     ios::sync_with_stdio(0), cin.tie(0);
     cin >> n;
     memset(h, -1, sizeof h);
     for(int i = 1; i < n ; i++ ) {
         int a, b;
         cin >> a >> b;
         add(a, b), add(b, a);
     }
     for(int i = 1; i <= n ; i++ ) {
         cin >> a[i] >> b[i] >> c[i];
         p[i] = b[i] * inv(c[i]) % mod;
         cur = (cur + a[i]) % mod;
     }
     dfs(1, 0);
     for(int i = 1; i <= n; i++ ) {
         for(int j = 1;j <= n ; j ++ ) {
            cout<<g[j][i]<<" ";
             if(j == 1) ans[i] = (ans[i] + g[j][i]) % mod;
             else ans[i] = (ans[i] + g[j][i] * (1 + mod - p[fa[j]]) % mod) % mod;
        }   
     }
     for(int i = 1; i <= n ; i++ ) 
         cout << ans[i] << endl;
 }