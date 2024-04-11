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

typedef double LD;
typedef long long LL;
typedef unsigned long long ULL;
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
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 0.5;
const LL INF = 1e9;
const LL mod = 1000003;
const LL LINF = 1e18 + 10;
const LL MAXN = 1e6 + 1;

int n, a, b;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> a >> b;
	if (a > b)
		swap(a, b);

	int x, y;
	bool ok = 0;
	for (int k = 0; k * a <= n; ++k)
	{
		if ((n - k * a) % b)
			continue;

		ok = 1;
		x = k;
		y = (n - k * a) / b;
		break;
	}

	if (!ok)
	{
		cout << -1;
		return 0;
	}

	int curr = 1;
	FOR(i, 0, x)
	{
		cout << curr + a - 1 << " ";
		FOR(j, curr, curr + a - 1)
			cout << j << " ";

		curr += a;
	}

	FOR(i, 0, y)
	{
		cout << curr + b - 1 << " ";
		FOR(j, curr, curr + b - 1)
			cout << j << " ";
		curr += b;
	}

	
	cin >> n;
	return 0;
}