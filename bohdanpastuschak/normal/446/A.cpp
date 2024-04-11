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
#include <complex>
#include <stdio.h>
#include <unordered_set>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const LL INF = 2e9 + 1;
const LL LINF = 1e12;
const LL MAXN = 2e3 + 1;
const LD EPS = 1e-6;

LL DP[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int n;
	cin >> n;
	VI a(n + 1);
	FOR(i, 0, n)
		cin >> a[i + 1];

	int ans = 0;
	VI l(n + 2, 0), r(n + 2, 0);
	FOR(i, 1, n + 1)
	{
		l[i] = l[i - 1] + 1;
		if (a[i] <= a[i - 1])
			l[i] = 1;
	}

	RFOR(i, n + 1, 1)
	{
		r[i] = r[i + 1] + 1;
		if (i < n && a[i] >= a[i + 1])
			r[i] = 1;
	}

	FOR(i, 1, n + 1)
		ans = max(ans, l[i]), ans = max(ans, r[i]);

	FOR(i, 1, n + 1)
		ans = max(ans, l[i - 1] + 1), ans = max(ans, r[i + 1] + 1);

	FOR(i, 2, n)
	{
		if (a[i - 1] + 1 < a[i + 1])
			ans = max(ans, l[i - 1] + r[i + 1] + 1);
	}

	cout << ans;
	cin >> n;
	return 0;
}