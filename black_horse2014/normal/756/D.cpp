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

const int MAXN = 5555;
const int MOD = 1e9+7;

int dp[MAXN][26];
int sum[MAXN];

char str[MAXN];

int r[MAXN];

int main() {
	int n;
	scanf("%d%s", &n, str+1);
	sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		int c = str[i] - 'a';
		for (int j = n; j > 0; j--) {
			sum[j] = (sum[j] - dp[j][c] + MOD) % MOD;
			dp[j][c] = (sum[j-1] - dp[j-1][c] + MOD) % MOD;
			sum[j] = (sum[j] + dp[j][c]) % MOD;
		}
	}
	int ret = 1, ans = 0;
	r[1] = 1;
	for (int i = 2; i <= n; i++) {
		r[i] = (LL)(MOD - r[MOD % i]) * (MOD / i) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		ans = (ans + 1LL * ret * sum[i]) % MOD;
		ret = 1LL * (n - i) * ret % MOD * r[i] % MOD;
	}
	cout << ans << endl;
	return 0;
}