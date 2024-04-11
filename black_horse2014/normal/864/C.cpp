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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int A, B, F, K; cin >> A >> B >> F >> K;
	int cur = B, pos = 0, npos = A, ans = 0;
	if (B < A - F || B < F) {
		puts("-1");
		return 0;
	}
	while (K--) {
		if (cur < abs(pos - F)) {
			puts("-1");
			return 0;
		}
		cur -= abs(pos - F);
		if (K > 0 && cur < abs(F - npos) * 2) {
			ans++;
			cur = B;
		} else if (K == 0 && cur < abs(F - npos)) {
			ans++;
			cur = B;
		}
		cur -= abs(F - npos);
		pos = A - pos, npos = A - npos;
	}
	cout << ans << endl;
	return 0;
}