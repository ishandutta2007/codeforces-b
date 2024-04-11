// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x, _; cin >> x >> _;
    vector<ll> ans;
    ll dst = 1;
    for(int i=30; i>=1; i--) {
        int cnt = (1<<i)-1;
        while(x >= cnt) {
            rep(j, i) ans.pb(dst);
            dst += MOD;
            x -= cnt;
        }
    }
    cout << ans.size() << endl;
    for(ll& j:ans) cout << j << ' ';
}