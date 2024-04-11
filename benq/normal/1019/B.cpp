#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int n; 
// vi seq;

int query(int x) {
    x %= n;
    if (x == 0) x = n;
    cout << "? " << x << endl;
    /*return seq[x-1];*/
    int t; cin >> t;
    return t;
}

int getDif(int x) {
    int t = query(x)-query(x+n/2);
    if (t == 0) {
        cout << "! " << x << endl;
        exit(0);
    }
    return t;
}

int sgn(int x) {
    if (x < 0) return 1;
    return -1;
}

int main() {
    cin >> n;
    /*F0R(i,n/2) seq.pb(i);
    F0Rd(i,n/2) seq.pb(i-1);
    rotate(seq.begin(),seq.begin()+3523,seq.end());*/
    if (n/2 % 2 == 1) {
        cout << "! -1" << endl;
        exit(0);
    }
    int l = 1, r = n/2+1;
    int L = getDif(1); int R = -L;
    while (1) {
        int m = (l+r)/2;
        int M = getDif(m);
        if (sgn(M) == sgn(L)) {
            l = m;
            L = M;
        } else {
            r = m;
            R = M;
        }
        // cout << "AH " << l << " " << r << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/