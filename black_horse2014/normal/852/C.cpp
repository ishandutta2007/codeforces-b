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

const int MAXN = 1e6+5;

int p[MAXN], n, a[MAXN];
int id[MAXN];
bool cmp(int i, int j) {
	return a[i] < a[j];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", p + 2 * i);
	
	for (int i = 0; i < n; i++) {
	
		int u = p[2 * i], v = p[2 * ((i + 1) % n)];
		a[i] = n - u - v;
		id[i] = i;
	}
	sort(id, id + n, cmp);
	for (int i = 0; i < n; i++) a[id[i]] = n - 1 - i;
	for (int i = 0; i < n; i++) printf("%d%s", a[i], i == n - 1 ? "\n" : " "); 
	return 0;
}