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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // TYPE ID (StackOverflow)
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    ll sumSquare[SZ];
    
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }
    
    int get(int x) { // path compression
    	if (par[x] != x) par[x] = get(par[x]);
    	return par[x];
    }
    
    void setEq(int x, int y) { // x -> y
    	x = get(x), y = get(y); 
    	assert (x != y);
    	par[x] = y; 
    	sz[y] += sz[x];
    	sumSquare[y] += sumSquare[x];
    }
};

DSU<MX> D;

int n, par[MX], sz[MX];
vi adj[MX], rec;
bool used[MX];
ll ans;

ll sq(ll x) { return x*x; }

void process(int x, int sgn = 1) {
    ans -= sgn*sq(D.sz[x]);
    ans -= sgn*D.sz[x]*D.sumSquare[x];
}

void dfs(int a, int b) {
    if (b) par[a] = b;
    sz[a] = 1;
    trav(x,adj[a]) if (x != b) {
        dfs(x,a); sz[a] += sz[x];
        D.sumSquare[a] += sq(sz[x]);
    }
    D.sumSquare[a] += sq(n-sz[a]);
    // pr("HUH",D.sumSquare[a]);
    process(a);
}

void color(int x) {
    if (!x) return;
    rec.pb(x); used[x] = 1;
}

void clr() {
    for (int i: rec) used[i] = 0;
    rec.clear();
}

void merge(int x) {
    int y = D.get(par[x]);
    process(x,-1), process(y,-1);
    D.sumSquare[y] -= sq(sz[x]);
    D.sumSquare[x] -= sq(n-sz[x]);
    D.setEq(x,y);
    process(y,1);
}

int co = 0;

void join(int a, int b) {
    a = D.get(a), b = D.get(b);
    co ++;
    int lca = -1;
    for (int A = a, B = b; ; swap(A,B)) {
        if (used[A]) { lca = A; break; } 
        color(A); A = D.get(par[A]); 
    }
    clr();
    for (int A = D.get(a); A != lca; A = D.get(A)) {
        /* if (co == 2) pr("A",A);
        else */
        merge(A);
    }
    for (int B = D.get(b); B != lca; B = D.get(B)) {
        /*if (co == 2) {
            pr("B",B);
            B = D.get(par[B]);
        } else */
        merge(B);
    }
}

void init() {
    setIO(); re(n);
    F0R(i,n-1) {
        int a,b; re(a,b);
        adj[a].pb(b), adj[b].pb(a);
    }
    ans = (ll)n*n*n-(ll)2*n*n+2*n;
    dfs(1,0);
}

int main() {
    // you should actually read the stuff at the bottom
    init();
    pr(ans);
    int q; re(q);
    F0R(i,q) {
        int a,b; re(a,b);
        join(a,b);
        pr(ans);
    }
    // n^3-2n^2+2n 
    // -sum(a*(b^2+c^2+...))
    // -sum(a^2)
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/