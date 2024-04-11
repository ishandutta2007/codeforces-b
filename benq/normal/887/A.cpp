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

string s;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	bool ok = 0;
	for (char c: s) if ( c == '1') ok = 1;
	if (!ok) {
	    cout << "no";
	    return 0;
	}
	while (s[0] == '0') s.erase(s.begin());
	for (int i = s.length()-1; i > 0; --i) {
	    if (s[i] == '1') s.erase(s.begin()+i);
	}
	if (s.length() >= 7) cout << "yes";
	else cout << "no";
}

// read!
// ll vs. int!