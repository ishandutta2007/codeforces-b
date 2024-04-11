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

int n,x,depth[200001], mx[200001], par[200001];
vi adj[200001];

void dfs(int x) {
    for (int i: adj[x]) if (i != par[x]) {
        par[i] = x;
        depth[i] = depth[x]+1;
        dfs(i);
    }
    mx[x] = depth[x];
    for (int i: adj[x]) if (i != par[x]) mx[x] = max(mx[x],mx[i]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> x;
	F0R(i,n-1) {
	    int a,b; cin >> a >> b;
	    adj[a].pb(b), adj[b].pb(a);
	}
	dfs(1);
	int d = 0, ans = 0;
	while (1) {
	    if (depth[x] == d+1) break;
	    if (depth[x] > d+2) x = par[x];
	    d++, ans += 2;
	}
	ans += 2*(mx[x]-depth[x]+1);
	cout << ans;
}

// read!
// ll vs. int!