#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <string.h>
#include <cstdio>
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
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1e5 + 47;

int n, k;
int a[MAX];
int color[256];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> k;
	FOR(i, 0, n)
		cin >> a[i];

	FILL(color, -1);
	FOR(i, 0, n)
	{
		if (color[a[i]] != -1)
		{
			cout << color[a[i]] << " ";
			continue;
		}

		FOR(c, max(0, a[i] - k + 1), 256)
		{
			if (color[c] == -1)
			{
				FOR(j, c, a[i] + 1)
					color[j] = c;
				cout << c << " ";
				break;
			}

			if (a[i] - color[c] < k)
			{
				FOR(j, c + 1, a[i] + 1)
					color[j] = color[c];
				cout << c << " ";
				break;
			}
		}
	}

	cin >> n;
	return 0;
}