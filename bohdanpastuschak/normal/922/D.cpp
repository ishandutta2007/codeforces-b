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
#include <cstring>
#include <stdio.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<LL> VI;
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
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const LL MAX = 1e3;

LL H, S;

int cmp4(PLL x, PLL y)
{
	return x.X * x.Y < y.X * y.Y;
}

int cmp7(PLL x, PLL y)
{
	return x.Y * y.X < x.X * y.Y;
}

LL get(VPLL& a)
{
	LL ans = 0;
	LL cnt = 0;
	FOR(i, 0, SZ(a))
	{
		ans += a[i].Y * cnt;
		cnt += a[i].X;
	}

	return ans;
}

LL solve(VPLL& a)
{
	LL res = 0;

	sort(ALL(a), cmp4);
	res = max(res, get(a));

	sort(ALL(a), cmp7);
	res = max(res, get(a));
	reverse(ALL(a));
	res = max(res, get(a));	

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	string SSS;
	getline(cin, SSS);
	vector<string> a(n);
	FOR(i, 0, n)
		getline(cin, a[i]);

	LL ans = 0;
	LL cnt = 0;

	FOR(i, 0, n)
	{
		cnt = 0;
		FOR(j, 0, SZ(a[i]))
			if (a[i][j] == 'h')
				ans += cnt;
			else
				cnt++;
	}

	cnt = 0;
	VLL s(n), h(n);
	FOR(i, 0, n)
	{
		s[i] = h[i] = 0;
		FOR(j, 0, SZ(a[i]))
			if (a[i][j] == 's')
				++s[i];
			else
				++h[i];
	}

	H = S = 0;
	FOR(i, 0, n)
		H += h[i], S += s[i];

	VPLL SS(n);
	FOR(i, 0, n)
		SS[i] = MP(s[i], h[i]);

	ans += solve(SS);
	cout << ans;
	cin >> n;	
	return 0;
}