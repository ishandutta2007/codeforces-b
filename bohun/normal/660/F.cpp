
 #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
 
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;	
int Q = 0;
struct cht {
	const ld INF = 1e18;
	struct line {
		mutable ll x, y, p;
		bool operator < (const line &a) const{
			return Q == 0 ? x > a.x : p < a.p;
		}
	};
	multiset <line> s;
	bool wywal(auto x, auto y) {
		if(y == s.end()) { x->p = INF; return 0; }
		if(x->x == y->x) x->p = (x->y <= y->y ? INF : -INF);
		else x->p = floor ((ld) (y->y - x->y) / (x->x - y->x));
		return x->p >= y->p;
	}
	
	void add(line a) {
		s.insert(a);
		auto z = s.find(a), y = z++, x = y;
		while(wywal(y, z))
			z = s.erase(z);
		if(x != s.begin() && wywal(--x, y)) wywal(x, y = s.erase(y));
		while((y = x) != s.begin() && (--x)->p >= y->p) 
			wywal(x, s.erase(y));
	}	
	
	ll opt(ll x) {
		Q = 1;
		auto l = s.lower_bound({0, 0, x});
		Q = 0;
		return l->x * x + l->y;
	}
};
 
const int nax = 200005;
int n;
int cost[nax];
 
ll step[nax], sum[nax], ans = 0;
 
cht go;
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &cost[i]);
		sum[i] = sum[i - 1] + cost[i];
		step[i] = step[i - 1] + (ll) i * cost[i];
	}
	
	for(int i = 1; i <= n; ++i) {
		ll B = (ll) sum[i - 1] * (i - 1) - step[i - 1];
		ll A = -(i - 1);
		go.add({-A, -B, 0});
		ans = max(ans, -go.opt(sum[i]) + step[i]);
	}
	cout << ans;
		
		
	
	
	return 0;
}