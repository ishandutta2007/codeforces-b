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
const int MX = 1<<18;
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

const pair<int,pi> ZZ = {-MOD,{-MOD,-MOD}};

int n,num;
ll lans;
pair<int,pi> bound[MX];
vector<pair<pi,pi>> v[MX];
vl sumNum[MX], sumUp[MX], sumDown[MX];

void ad(int x) {
	if (bound[x].f == num) return;
	assert(bound[x] != ZZ);
	v[x].pb({{bound[x].f,num-1},bound[x].s});
	ll z = num-bound[x].f;
	sumNum[x].pb(sumNum[x].back()+z);
	sumUp[x].pb(sumUp[x].back()+z*bound[x].s.s);
	sumDown[x].pb(sumDown[x].back()+z*(bound[x].s.f-1));
}

template<class T, int SZ> struct Seg { // SZ should be power of 2
    T seg[2*SZ];

    Seg() { F0R(i,2*SZ) seg[i] = -MOD; }
    T comb(T a, T b) { return min(a,b); }
    // easily change this to min or max
    // comb(ID,b) must equal b

    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]);
            // make sure non-commutative operations work
    }

    pi fst(int R) {  
    	int ind = 1, l = 0, r = SZ-1;
    	while (l != r) {
    		int m = (l+r)/2;
    		if (seg[2*ind] < R) ind = 2*ind, r = m;
    		else ind = 2*ind+1, l = m+1;
    	}
    	return {l,seg[ind]};
    }
};

Seg<int,MX> lst;

void whoops(int a, int l, int r) {
	pi z = lst.fst(r); // z.f, lst[z.f] where lst[z.f] < r
	if (z.s >= l) {
		bound[z.f] = {num,{z.s+1,r}};
		whoops(z.f,l,z.s);
	} else {
		if (bound[z.f] != ZZ) {
			ad(z.f);
			bound[z.f].f = num;
			bound[z.f].s.s = r;
		} else {
			bound[z.f] = {num,{l,r}};
		}
	}
	// first z > a such that lst[a] < r
	// lst[a]+1 to r -> z
}

ll inter(pair<pi,pi> a, pair<pi,pi> b) {
	int x = min(a.f.s,b.f.s)-max(a.f.f,b.f.f)+1;
	int y = min(a.s.s,b.s.s)-max(a.s.f,b.s.f)+1;
	if (min(x,y) <= 0) return 0;
	return (ll)x*y;
}

int leftLeast(vector<pair<pi,pi>>& v, int x) {
	int l = 0, r = sz(v);
	while (l < r) {
		int m = (l+r)/2;
		if (v[m].s.f >= x) r = m;
		else l = m+1;
	}
	return l;
}

int rightLeast(vector<pair<pi,pi>>& v, int x) {
	int l = 0, r = sz(v);
	while (l < r) {
		int m = (l+r)/2;
		if (v[m].s.s >= x) r = m;
		else l = m+1;
	}
	return l;
}

int up(vector<pair<pi,pi>>& v, int x) {
	// last one such that t.f.f <= r
	int l = -1, r = sz(v)-1;
	while (l < r) {
		int m = (l+r+1)/2;
		if (v[m].f.f <= x) l = m;
		else r = m-1;
	}
	return l;
}

ll query(int l, int r, int k) {
	ll ret = 0;
	pair<pi,pi> des = {{l,r},{l,r}};
	if (bound[k] != ZZ) ret += inter(des,{{bound[k].f,num},bound[k].s});
	// trav(t,v[k]) ret += inter({{l,r},{l,r}},t); // SPEED UP
	int i0 = rightLeast(v[k],l);
	int i1 = leftLeast(v[k],l);
	int i2 = up(v[k],r);
	if (i0 <= i2) {
		ret += inter(des,v[k][i2]);
		ret += sumUp[k][i2]-sumUp[k][i0];
		if (i1 > i2) {
			ret -= (sumNum[k][i2]-sumNum[k][i0])*(l-1);
		} else {
			ret -= (sumNum[k][i1]-sumNum[k][i0])*(l-1);
			ret -= (sumDown[k][i2]-sumDown[k][i1]);
		}
	}
	/*ps("HUH",i0,i1,i2,ret,sz(v[k]));
	ps("HA",ret);
	ps(l,r,v[k]);*/
	return ret;
}

int main() {
    setIO(); re(n); 
    F0R(i,n+1) {
    	bound[i] = ZZ; 
    	sumUp[i] = sumDown[i] = sumNum[i] = {0};
    }
    while (num < n) {
    	int a,l,r,k; re(a,l,r,k);
    	a = (a+lans)%(n+1); 
    	lst.upd(a,num);
    	if (bound[0] == ZZ) {
    		bound[0] = {num,{num,num}};
    	} else {
    		ad(0);
    		bound[0].f = bound[0].s.s = num;
    	}
    	if (bound[a] != ZZ) {
    		ad(a);
    		pi p = bound[a].s; bound[a] = ZZ;
	    	whoops(a,p.f,p.s);
    	}
    	l = (l+lans)%(num+1);
    	r = (r+lans)%(num+1);
    	if (l > r) swap(l,r);
    	k = (k+lans)%(n+1);
    	lans = query(l,r,k);
    	ps(lans); num ++;
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/