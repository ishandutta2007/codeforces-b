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
const ll INF = 1e18;
const int MX = 100001;

int c[3];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string S; cin >> S;
    int ind = 0;
    while (ind < sz(S) && S[ind] == 'a') c[0] ++, ind ++;
    while (ind < sz(S) && S[ind] == 'b') c[1] ++, ind ++;
    while (ind < sz(S) && S[ind] == 'c') c[2] ++, ind ++;
    if (ind != sz(S) || c[0] == 0 || c[1] == 0 || c[2] == 0) {
        cout << "NO";
        return 0;
    }
    if (c[0] != c[2] && c[1] != c[2]) {
        cout << "NO";
        return 0;
        
    }
    cout << "YES";
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)