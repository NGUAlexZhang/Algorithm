#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long int_;
inline int readint(){
	int a = 0; char c = getchar(), f = 1;
	for(; c<'0'||c>'9'; c=getchar())
		if(c == '-') f = -f;
	for(; '0'<=c&&c<='9'; c=getchar())
		a = (a<<3)+(a<<1)+(c^48);
	return a*f;
}
template < typename T >
inline void getMax(T &a,const T &b){
	(a < b) ? (a = b) : 0;
}
template < typename T >
inline void getMin(T &a,const T &b){
	(b < a) ? (a = b) : 0;
}

const int MaxN = 2010;
const int Mod = 1e9+7;
int a[MaxN], dp[MaxN][MaxN], n;
struct BIT{
	int c[MaxN];
	void clear(){
		for(int i=1; i<=n; ++i)
			c[i] = 0;
	}
	void modify(int id,int v){
		for(int i=id; i<=n; i+=(i&-i))
			c[i] = (c[i]+v)%Mod;
	}
	int query(int id){
		if(id > n) id = n;
		int res = 0;
		for(int i=id; i; i-=(i&-i))
			res = (res+c[i])%Mod;
		return res;
	}
};
BIT r[MaxN]; // 每个右端点都开一个
BIT cnt, l; // cnt是个数 l是当前左端点
int_ inv[MaxN]; // 逆元
int main(){
	n = readint();
	for(int i=1; i<=n; ++i)
		a[i] = readint();
	inv[1] = 1; // 预处理逆元
	for(int i=2; i<=n; ++i)
		inv[i] = (Mod-Mod/i)
			* inv[Mod%i]%Mod;
	a[n+1] = n+1; // 末尾的虚点
	for(int i=n-1; i>=0; --i){
		l.clear(), cnt.clear();
		for(int j=i+2; j<=n+1; ++j){
			r[j].modify(a[i+1],dp[i+1][j]);
			l.modify(a[j-1],dp[i][j-1]);
			cnt.modify(a[j-1],1);
			int s = cnt.query(a[j])
				- cnt.query(a[i]);
			if(s <= 0) continue;
			int all = l.query(a[j])
				- l.query(a[i])
				+ r[j].query(a[j])
				- r[j].query(a[i]);
			all = (all%Mod+Mod)%Mod;
			dp[i][j] = (all*inv[s]+1)%Mod;
// printf("dp[%d,%d] = %d\n",i,j,dp[i][j]);
		}
	}
	printf("%d\n",dp[0][n+1]);
    for(int i=0;i<=n+1;i++)
    for(int j=0;j<=n+1;j++) cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	return 0;
}
