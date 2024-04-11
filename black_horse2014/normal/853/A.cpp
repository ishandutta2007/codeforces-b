#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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

const int MAXN = 310000;

int c[MAXN], t[MAXN];
set<PII> S;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= k; i++) S.insert(PII(-c[i], i));
	long long ans = 0;
	for (int i = k+1; i <= n+k; i++) {
		if (i <= n) S.insert(PII(-c[i], i));
		int j = S.begin()->second;
		ans += 1LL * c[j] * (i - j);
		t[j] = i;
		S.erase(S.begin());
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) printf("%d ", t[i]);
	puts("");
	return 0;
}