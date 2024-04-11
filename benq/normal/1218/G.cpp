#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef string str;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
		cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
	a %= b; if (a == 0) return b == 1 ? 0 : -1;
	T x = invGeneral(b,a); 
	return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
	T val; 
	explicit operator T() const { return val; }
	modular() { val = 0; }
	modular(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	
	// friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
	friend void pr(const modular& a) { pr(a.val); }
	friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
	friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		auto i = invGeneral(a.val,MOD); assert(i != -1);
		return i;
	} // equivalent to return exp(b,MOD-2) if MOD is prime
	modular& operator/=(const modular& m) { return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { return a += b; }
	friend modular operator-(modular a, const modular& b) { return a -= b; }
	friend modular operator*(modular a, const modular& b) { return a *= b; }
	
	friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int N,M, col[MX], act[MX], depth[MX], val[MX];
pi par[MX];
vpi span[MX];
string c;
vpi adj[MX], ed;
vi cyc;

void dfs(int x, int y) {
	col[x] = y;
	trav(t,adj[x]) {
		if (col[t.f] == -1) {
			span[x].pb({t.f,t.s}), span[t.f].pb({x,t.s});
			par[t.f] = {x,t.s};
			depth[t.f] = depth[x]+1;
			dfs(t.f,y^1);
		} else {
			if (col[t.f] != (col[x]^1)) {
				cyc = {x,t.f,t.s};
			}
		}
	}
}


bool vis[MX];

void ad(int a, int b) {
	b = (b+3)%3;
	val[a] = (val[a]+b)%3;
	act[ed[a].f] = (act[ed[a].f]+b)%3;
	act[ed[a].s] = (act[ed[a].s]+b)%3;
}

void fix2(int x, int y) {
	trav(t,span[x]) if (t.f != y) {
		fix2(t.f,x); ad(t.s,col[t.f]-act[t.f]);
	}
}

void solve2() {
	int cool = -1;
	F0R(i,N) if (sz(span[i]) > 1) cool = i;
	fix2(cool,-1);
	if (act[cool] == act[span[cool][0].f]) {
		ad(span[cool][0].s,2-act[span[cool][0].f]);
		ad(span[cool][1].s,2-act[span[cool][1].f]);
	}
	// exit(0);
}

void fix(int x) {
	vis[x] = 1;
	trav(t,adj[x]) if (!vis[t.f]) {
		fix(t.f); ad(t.s,col[t.f]-act[t.f]);
		// ps("WUT",x,t.f);
	}
}

void solve3() {
	vi x, y;
	int cool = cyc[0];
	while (cyc[0] != cyc[1]) {
		if (depth[cyc[0]] > depth[cyc[1]]) {
			x.pb(par[cyc[0]].s);
			cyc[0] = par[cyc[0]].f;
		} else {
			y.pb(par[cyc[1]].s);
			cyc[1] = par[cyc[1]].f;
		}
	}
	reverse(all(y)); x.insert(end(x),all(y)); x.pb(cyc[2]);
	// ps("HUH",x,cool);
	F0R(i,N) col[i] = c[i]-'X';
	fix(cool); 
	while (act[cool] != col[cool]) {
		F0R(i,sz(x)) {
			int sgn = 1; if (i&1) sgn = -1;
			ad(x[i],sgn);
		}
	}
	F0R(i,N) assert(act[i] == col[i]);
}

int main() {
	// setIO("ZZ"); 
	setIO();
	re(N,M); 
	re(c); F0R(i,N) col[i] = -1;
	// ps("HA"); exit(0);
	F0R(i,M) {
		int u,v; re(u,v); ed.pb({u,v});
		adj[u].pb({v,i}), adj[v].pb({u,i});
	}
	dfs(1,0);
	// ps("CYC",cyc); exit(0);
	if (!sz(cyc)) solve2();
	else solve3();
	F0R(i,sz(ed)) {
		int v = val[i]; if (v == 0) v = 3;
		ps(ed[i].f,ed[i].s,v);
		assert(act[ed[i].f] != act[ed[i].s]);
	}
	// ps(x);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/