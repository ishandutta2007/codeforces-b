// @betaveros :: vim:set fdm=marker syntax=cppc:
#define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
// #include <cinttypes> // C++11?
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
#include <iostream>
using namespace std;
// }}}
// #defines, typedefs, constants {{{
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define foruin(i,c) for(unsigned int i = 0; i < ((unsigned int)(c).size()); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define scan_d(x) scanf("%d",&(x))
#define scan_dd(x,y) scanf("%d%d",&(x),&(y))
#define scan_ddd(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan_dddd(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define pushb push_back
#define popb push_back

#ifdef NDEBUG
#define debug(code)
#define debugf(...) ((void)0)
#else
#define debug(code) code
#define debugf(...) fprintf(stderr, __VA_ARGS__)
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> Vint;
typedef vector<int>::iterator Vit;

// const int OO  = 1000 << 20;
// const int OO2 = 2000 << 20;
// const int       M7  = 1000000007;
// const int       M9  = 1000000009;
// const long long M7L = 1000000007L;
// }}}
// dump, min/maxify {{{
template <class T> void dumpBetween(const T & a, const T & b) {
	for (T it = a; it != b; it++) cout << *it << " ";
	cout << endl;
}
template <class T> void dumpAll(const T & a) { dumpBetween(allof(a)); }
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }
// }}}

const int N = 100008;
int n, m;
int animals[N];
vector<int> graph[N];
void readInput() {
	scan_dd(n, m);
	fori (i, 1, n+1) scan_d(animals[i]);
	repeat(m) {
		int x, y;
		scan_dd(x, y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
}

int ixs[N];
bool icmp(int a, int b) {
	if (animals[a] != animals[b]) return animals[a] > animals[b];
	return a < b;
}

int parent[N];
int size[N];

int root(int a) {
	if (parent[a] == a) return a;
	return parent[a] = root(parent[a]);
}

int link(int a, int b) {
	int ra = root(a);
	int rb = root(b);
	if (ra == rb) return 0;
	parent[rb] = ra;
	size[ra] += size[rb];
	return size[rb];
}
ll c2(ll x) {
	return x * (x - 1) / 2;
}
void tc() {
	readInput();
	fori (i, 0, n) { ixs[i] = i+1; }
	fori (i, 1, n+1) { parent[i] = i; size[i] = 1; }
	sort(ixs, ixs + n, icmp);
	ll num = 0;
	fori (i, 0, n) {
		int v = ixs[i];
		debugf("v = %d\n", v);
		int s = 1;
		ll s2 = 0;
		foruin (j, graph[v]) {
			int w = graph[v][j];
			if (animals[w] < animals[v] ||
					(animals[w] == animals[v] && w > v)) continue;
			debugf("link vs %d\n", w);
			int lres = link(v, w);
			s += lres;
			s2 += c2(lres);
		}
		ll npairs = c2(s) - s2;
		num += npairs * (ll)animals[v];
	}
	printf("%.15lf\n", ((double)num) / ((double)c2(n)));
}

int main() { tc(); }