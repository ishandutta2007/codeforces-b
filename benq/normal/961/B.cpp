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
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

ll n,k,cum[100001],CUM[100001],t[100001];
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    FOR(i,1,n+1) {
        cin >> cum[i]; 
        cum[i] += cum[i-1];
    }
    FOR(i,1,n+1) cin >> t[i];
    FOR(i,1,n+1) {
        CUM[i] = (cum[i]-cum[i-1])*t[i];
        CUM[i] += CUM[i-1];
    }
    F0R(i,n+1-k) ans = max(ans,CUM[i]+cum[i+k]-cum[i]+CUM[n]-CUM[i+k]);
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)