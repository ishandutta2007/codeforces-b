#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const ll MOD = 998244353;
const int MN = 5e5 + 5;
int t, n;
ll dp[MN], dp1[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        ll total = 0;
        dp[0] = 1;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            total += dp[a-1] + dp[a] + dp[a+1] + dp1[a] + dp1[a+2];
            total %= MOD;
            dp1[a] += dp1[a] + dp[a-1];
            dp1[a+2] += dp1[a+2];
            dp[a+1] += dp[a+1] + dp[a];
            dp1[a] %= MOD;
            dp1[a+2] %= MOD;
            dp[a+1] %= MOD;
        }
        cout << total << '\n';
        fill(dp, dp + n+3, 0);
        fill(dp1, dp1 + n+3, 0);
    }
}