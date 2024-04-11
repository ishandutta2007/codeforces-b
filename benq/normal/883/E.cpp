#include <bits/stdc++.h> //
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

int n, m, ok = (1<<26)-1;
string s;

void match(string a) {
    int done = 0, num = 0;
    F0R(i,s.length()) if (s[i] != '*' && s[i] != a[i]) return;
    F0R(i,s.length()) if (s[i] != '*') {
        done |= 1<<int(s[i]-'a');
        num++;
    }
    
    int res = 0;
    F0R(i,a.length()) if ((1<<int(a[i]-'a'))&done) num --;
    else res |= 1<<int(a[i]-'a');
    
    if (num != 0) return;
    ok &= res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> s >> m;
	F0R(i,m) {
	    string tmp; cin >> tmp;
	    match(tmp);
	}
	cout << __builtin_popcount(ok);
}

// read!
// ll vs. int!