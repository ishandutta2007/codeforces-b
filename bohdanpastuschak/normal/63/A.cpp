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
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <tuple>

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define ld long double
#define ll long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) ll((a).size())
#define X first
#define Y second

#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vch vector<char>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define pq priority_queue
#define mod 1000000007
#define PI 3.141592653589793
using namespace std;

const ll INF = 1e18;
const ll MAXN = 101;

vi pref(string s)
{
	int n = (int)s.length();
	vi pi(n);
	int j;
	FOR(i,1,n)
	{
		j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			++j;
		pi[i] = j;
	}
	return pi;
}

bool can(pair<pair<string, string>, int> a, pair<pair<string, string>, int> b)
{
	if (b.X.Y == "woman")
		b.X.Y = "child";

	if (a.X.Y == "woman")
		a.X.Y = "child";

	if (a.X.Y == b.X.Y)
		return a.Y < b.Y;

	if (a.X.Y == "rat")
		return 1;
	if (b.X.Y == "rat")
		return 0;
	if (a.X.Y == "child")
		return 1;
	if (a.X.Y == "captain")
		return 0;

	if (b.X.Y == "child")
		return 0;

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("strings.in", "r", stdin);
	//freopen("strings.out", "w", stdout);

	int n;
	cin >> n;
	vector<pair<pair<string, string>, int>> s(n);
	FOR(i, 0, n)
		cin >> s[i].X.X >> s[i].X.Y, s[i].Y = i;

	sort(ALL(s), can);
	FOR(i, 0, n)
		cout << s[i].X.X << endl;
	cin >> n;
	return 0;
}