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

const int MAXN = 333333;

VI adj[MAXN], con[MAXN];
int x[MAXN], id[MAXN], rid[MAXN];

bool cmp(int u, int v) {
	if (adj[u].size() != adj[v].size()) return adj[u].size() < adj[v].size();
	for (int i = 0; i < sz(adj[u]); i++) {
		if (adj[u][i] != adj[v][i]) return adj[u][i] < adj[v][i];
	}
	return 0;
}

bool equal(int u, int v) {
	if (adj[u].size() != adj[v].size()) return 0;
	for (int i = 0; i < sz(adj[u]); i++) {
		if (adj[u][i] != adj[v][i]) return 0;
	}
	return 1;
}

void dfs(int u, int p, int y) {
	x[u] = y;
	for (int i = 0; i < sz(con[u]); i++) {
		int v = con[u][i];
		if (v == p) continue;
		dfs(v, u, y + 1);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) adj[i].push_back(i);
	for (int i = 1; i <= n; i++) sort(all(adj[i])), adj[i].erase(unique(all(adj[i])), adj[i].end());
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	int cnt = 0;
	for (int i = 1, j; i <= n; i = j) {
		++cnt;
		for (j = i; j <= n && equal(id[i], id[j]); j++) rid[id[j]] = cnt;
	}
	if (cnt == 1) {
		puts("YES");
		for (int i = 1; i <= n; i++) printf("1 ");
		puts("");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz(adj[i]); j++) {
			int k = adj[i][j];
			if (rid[i] != rid[k]) con[rid[i]].pb(rid[k]);
		}
	}
	for (int i = 1; i <= cnt; i++) {
		sort(all(con[i]));
		con[i].erase(unique(all(con[i])), con[i].end());
		if (con[i].size() > 2) {
			puts("NO");
			return 0;
		}
	}
	int tot = 0;
	for (int i = 1; i <= cnt; i++) if (con[i].size() == 1) {
		dfs(i, 0, 1);
		tot++;
		break;
	}
	if (tot == 0) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d ", x[rid[i]]);
	puts("");
	return 0;
}