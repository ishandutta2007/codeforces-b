#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define rsz resize
#define ins insert 

#define mp make_pair
#define pb push_back
#define eb emplace_back 
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 2e5+5;
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...); 
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

typedef decay<decltype(MOD)>::type T;
struct mi {
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	// friend ostream& operator<<(ostream& os, const mi& a) { 
		// return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
   
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(a != 0); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<class T> T poll(pqg<T>& x) {
	T y = x.top(); x.pop(); return y; }

template<int SZ> struct MCMF { 
	typedef ll F; typedef ll C;
	struct Edge { int to, rev; F flow, cap; C cost; };
	vector<Edge> adj[SZ];
	void ae(int u, int v, F cap, C cost) {
		assert(cap >= 0);
		Edge a{v,sz(adj[v]),0,cap,cost}, b{u,sz(adj[u]),0,0,-cost};
		adj[u].pb(a), adj[v].pb(b);
	}
	int N, s, t;
	pi pre[SZ]; // previous vertex, edge label on path
	pair<C,F> cost[SZ]; // tot cost of path, amount of flow
	C totCost, curCost; F totFlow; 
	bool spfa() { // find lowest cost path such that you can send flow through it
		F0R(i,N) cost[i] = {numeric_limits<C>::max(),0}; 
		cost[s] = {0,numeric_limits<F>::max()};
		pqg<pair<C,int>> todo; todo.push({0,s});
		while (sz(todo)) {
			auto x = poll(todo); if (x.f > cost[x.s].f) continue;
			trav(a,adj[x.s]) if (a.flow < a.cap 
				&& ckmin(cost[a.to].f,x.f+a.cost)) { 
				// if costs are doubles, add some small constant so
				// you don't traverse some ~0-weight cycle repeatedly
				pre[a.to] = {x.s,a.rev};
				cost[a.to].s = min(a.cap-a.flow,cost[x.s].s);
				todo.push({cost[a.to].f,a.to});
			}
		}
		return cost[t].s;
	}
	void backtrack() {
		F df = cost[t].s; totFlow += df;
		curCost += cost[t].f; totCost += curCost*df;
		for (int x = t; x != s; x = pre[x].f) {
			adj[x][pre[x].s].flow -= df;
			adj[pre[x].f][adj[x][pre[x].s].rev].flow += df;
		}
		F0R(i,N) trav(p,adj[i]) p.cost += cost[i].f-cost[p.to].f;
		// all reduced costs non-negative
		// edges on shortest path become 0
	}
	pair<F,C> calc(int _N, int _s, int _t) {
		N = _N; s = _s, t = _t; totFlow = totCost = curCost = 0;
		while (spfa()) backtrack();
		return {totFlow,totCost};
	}
};

MCMF<1500> M;

int n,m,win[51];
int res[51][51];

int main() {
	cin.sync_with_stdio(0); cin.tie(0); 
	re(n,m);
	FOR(i,1,n+1) FOR(j,1,n+1) {
		if (i == j) res[i][j] = 0;
		else res[i][j] = -1;
	}
	F0R(i,m) {
		int u,v; re(u,v);
		win[u] ++;
		res[u][v] = 1, res[v][u] = 0;
	}
	FOR(i,1,n+1) {
		FOR(j,win[i],n) M.ae(i,0,1,j);
	}
	int cnt = n+1, num = 0;
	FOR(i,1,n+1) FOR(j,i+1,n+1) if (res[i][j] == -1) {
		cnt ++;
		M.ae(cnt,i,1,0);
		M.ae(cnt,j,1,0);
		M.ae(n+1,cnt,1,0);
		num ++;
	}
	auto z = M.calc(cnt+1,n+1,0);
	cnt = n+1;
	FOR(i,1,n+1) FOR(j,i+1,n+1) if (res[i][j] == -1) {
		cnt ++; int up = 0;
		trav(t,M.adj[cnt]) if (t.flow > 0) {
			int label = t.to; assert(label == i || label == j);
			res[label][i+j-label] = 1;
			res[i+j-label][label] = 0;
			up ++;
		}
		// ps("WUT",i,j,up);
	}
	FOR(i,1,n+1) {
		FOR(j,1,n+1) pr(res[i][j]);
		ps();
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/