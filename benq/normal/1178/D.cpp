#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
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
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool prime(int x) {
	if (x <= 1) return 0;
	for (int i = 2; i*i <= x; ++i) if (x%i == 0) return 0;
	return 1;
}

void check(int X, vpi v) {
	vi deg(X+1);
	bool bad = !prime(sz(v));
	trav(t,v) {
		deg[t.f] ++, deg[t.s] ++;
	}
	FOR(i,1,X+1) bad |= !prime(deg[i]);
	assert(!bad);
	if (bad) {
		ps(-1);
	} else {
		ps(sz(v));
		trav(t,v) ps(t.f,t.s);
	}
}

void solve(int x) {
	int X = x;
	int t = x; while (!prime(t)) t ++;
	vpi ed;
	if (x == 6) {
		F0R(i,6) ed.pb({i+1,(i+1)%6+1});
		ed.pb({1,3});
		check(X,ed);
		return;
	}
	while (x > 0 && x%4 != 0) {
		if (x%4 == 1) {
			ed.pb({x,x-4});
			ed.pb({x-3,x-4});
			ed.pb({x-2,x-3});
			ed.pb({x-2,x-1});
			ed.pb({x-1,x});
			t -= 5; x -= 5;
		} else {
			ed.pb({x-2,x-1});
			ed.pb({x-1,x});
			ed.pb({x-2,x});
			t -= 3; x -= 3;
		}
	}
	assert(x >= 0);
	while (x) {
		int z = 4+min(t-x,2);
		ed.pb({x-3,x-2});
		ed.pb({x-2,x-1});
		ed.pb({x-1,x-0});
		ed.pb({x-0,x-3});
		if (z >= 5) ed.pb({x-3,x-1});
		if (z >= 6) ed.pb({x-2,x});
		t -= z, x -= 4;
	}
	check(X,ed);
}

int main() {
    setIO(); 
	int n; re(n);
	solve(n);
	// FOR(i,0,11) ps(i,prime(i));
	/*FOR(i,3,1001) {
		// ps(i);
		solve(i);
		// ps("-----");
		// exit(0);
	}*/
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/