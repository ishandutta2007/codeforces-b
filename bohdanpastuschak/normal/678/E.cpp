#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <unordered_map>
#include <complex>
#include <stdio.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL MAX = 2e5 + 7;
const LL MAXN = 18;
const LD EPS = 1e-9;

int n;
char used[1 << MAXN][MAXN];
LD DP[1 << MAXN][MAXN];
LD A[MAXN][MAXN];

LD solve(int mask, int x)
{	
	if (mask == (1 << n) - 1)
		return DP[mask][x] = (x == 0);

	used[mask][x] = 1;
	DP[mask][x] = 0;

	FOR(i, 0, n)
	{
		if (mask & (1 << i))
			continue;

		int m = mask | (1 << i);
		if (used[m][i] == 0)
			solve(m, i);

		if (used[m][x] == 0)
			solve(m, x);

		DP[mask][x] = max(DP[mask][x], A[x][i] * DP[m][x] + A[i][x] * DP[m][i]);
	}

	return DP[mask][x];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	FOR(i, 0, n)
		FOR(j, 0, n)
		cin >> A[i][j];

	LD ans = 0;
	LD curr;
	FOR(i,0,n)
		FOR(j, i + 1, n)
	{
		int mask = (1 << i) | (1 << j);
		curr = solve(mask, i) * A[i][j] + solve(mask, j) * A[j][i];
		ans = max(ans, curr);
	}

	cout << fixed << setprecision(10) << ans;
	cin >> n;
	return 0;
}