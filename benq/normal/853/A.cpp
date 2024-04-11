#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;

ll n,k, f[300000], ans[300000];
ll csum = 0, sum = 0;
priority_queue<pii> vals;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n) cin >> f[i];
	F0R(i,k) {
	    vals.push({f[i],i});
	    sum += (k-i)*f[i];
	    csum += f[i];
	}
	FOR(i,k,n+k) {
	    if (i < n) {
	        vals.push({f[i],i});
	        csum += f[i];
	    }
	    csum -= vals.top().f;
	    ans[vals.top().s] = i+1;
	    vals.pop();
	    sum += csum;
	}
	cout << sum << "\n";
	F0R(i,n) cout << ans[i] << " ";
}

// read!
// ll vs. int!