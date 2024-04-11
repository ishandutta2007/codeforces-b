#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <iterator>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
#include <sstream>
using namespace std;

#define ll long long
#define mod 1000000007
#define ld long double
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define pdd pair<ld,ld>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<int>//ll
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define vch vector<char>
#define vb vector<bool>
#define vld vector<ld>
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 20001

int segment_tree[4*MAXN];

void build_tree(vi a, int v, int tl, int tr)
{
	if (tl == tr)
		segment_tree[v] = a[tl];
	else
	{
		int tm = (tl + tr) / 2;
		build_tree(a, 2 * v, tl, tm);
		build_tree(a, 2 * v + 1, tm + 1, tr);
		segment_tree[v] = segment_tree[2 * v + 1] + segment_tree[2 * v];
	}
}

int sum_tree(int v, int tl, int tr, int l, int r)
{
	if (l <= r)
	{
		if (l == tl && r == tr)
			return segment_tree[v];
		
		int tm = (tl + tr) / 2;

		return sum_tree(2 * v, tl, tm, l, min(tm, r)) + sum_tree(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
	}
	else
		return 0;
}

void update_tree(int v, int tl, int tr, int index, int val)
{
	if (tl == tr)
		segment_tree[v] = val;
	else
	{
		int tm = (tl + tr) / 2;
		if (index <= tm)
			update_tree(2 * v, tl, tm, index, val);
		else
			update_tree(2 * v + 1, tm + 1, tr, index, val);

		segment_tree[v] = segment_tree[2 * v + 1] + segment_tree[2 * v];
	}
}

vi g[MAXN];

int bfs(int v, int m)
{
	vch used;
	vi dist;
	used.assign(MAXN, 0);
	dist.assign(MAXN, 0);

	queue<int> q;
	q.push(v);

	used[v] = 1;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (t >= 1 && t < MAXN)
			for(auto i: g[t])
				if (i >= 1 && i < MAXN && used[i] == 0)
				{
					used[i] = 1;
					dist[i] = dist[t] + 1;
					q.push(i);
				}
	}
	return dist[m];
}

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	ll n, m;
	cin >> n >> m;

	FOR(i, 1, MAXN)
		g[i].push_back(2 * i), g[i].push_back(i - 1);

	cout << bfs(n, m);

	return 0;
}
//don't forget about MAXN, mod and infinity