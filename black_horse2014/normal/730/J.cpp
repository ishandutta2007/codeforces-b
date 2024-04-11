#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
#define MX 111
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
int k, t, a[MX], tot, id[MX], dp[MX][MX * MX], b[MX], s, n;

bool cmp(int u, int v) {
	return b[u] > b[v];
}
int main() {
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), tot += a[i];
	for(int i = 0; i < n; i++) scanf("%d", &b[i]), id[i] = i;
	sort(id, id + n, cmp);
	for(int i = 0; i < n; i++) {
		s += b[id[i]];
		if(s >= tot) {
			k = i + 1;
			break;
		}
	}
	for (int i = 0; i <= k; i++) for (int j = 0; j < MX*MX; j++) dp[i][j] = -1e8;
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = k; j >= 1; j--) 
			for(int l = 0; l < MX * MX - b[i]; l++) {
				chkmax(dp[j][l + b[i]], dp[j - 1][l] + a[i]);
			}
	}
	t = 1e8;
	for(int j = tot; j < MX * MX; j ++) chkmin(t, tot - dp[k][j]);
	cout<< k << " " << t<< endl;
 	return 0;
}