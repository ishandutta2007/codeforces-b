#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 210000;

VI V[MAXN];
int a[MAXN], b[MAXN], d[MAXN], dp[MAXN];

int get(int u, int m) {
	int ret = 0;
	for (; u <= m; u += u & -u) chkmax(ret, dp[u]);
	return ret;
}

void add(int u, int x) {
	for (; u; u -= u & -u) chkmax(dp[u], x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i-1] = a[i];
	sort(b, b + n);
	int m = unique(b, b + n) - b;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(b, b + m, a[i]) - b + 1;
	for (int i = 1; i <= n; i++) {
		d[i] = get(a[i], m) + 1;
		add(a[i], d[i]);
		V[d[i]].push_back(b[a[i]-1]);
	}
	for (int i = 1; i <= n; i++) if (!V[i].empty()) {
		for (auto u : V[i]) printf("%d ", u);
		puts("");
	}
	return 0;
}