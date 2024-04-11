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
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<char> VCH;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define X first
#define Y second
#define MP make_pair

#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define FOR(i,a,b)  for(LL i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(LL i= (b) - 1; i >= (a); --i)

const LL MAXN = 100001;
const LL INF = 1e9;
const LL mod = 1000000007;

//int t[MAXN];
int n;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;

	VLL a(n);
	FOR(i, 0, n)
		cin >> a[i];

	set<int> is;
	FOR(i, 0, n)
		is.insert(i);

	int ans;
	cout << 1 << " ";
	FOR(i, 1, n)
	{
		is.erase(a[i - 1] - 1);
		int last = *is.rbegin();
		ans = 1 + abs(n - i - last - 1);
		cout << ans << " ";
	}

	cout << 1;
	//cin >> n;
	return 0;
}