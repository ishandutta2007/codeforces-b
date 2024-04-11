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
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
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

#define FOR(i,a,b) for(LL i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(LL i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e7 - 1;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const int MAXN = 1e5 + 7;
const int MAXK = 31;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	LL n, a, b;
	cin >> n >> a >> b;
	if (a > b)
		swap(a, b);
	VI now;
	FOR(i, 1, n + 1)
		now.push_back(i);

	int ans = 1;
	while (SZ(now) > 1)
	{
		VI next;
		for (int i = 0; i < SZ(now); i += 2)
		{
			int x = now[i];
			int y = now[i + 1];
			if (x > y)
				swap(x, y);

			if (x == a && y == b)
			{
				if (SZ(now) == 2)
				{
					cout << "Final!";
					return 0;
				}

				cout << ans;
				return 0;
			}

			if (x == a || x == b)
				next.push_back(x);
			else
				next.push_back(y);
		}

		now = next;
		++ans;
	}

	cin >> n;
	return 0;
}