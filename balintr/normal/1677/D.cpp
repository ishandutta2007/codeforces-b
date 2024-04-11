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
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << arr[_i]; cerr << endl;}

const int MOD = 998244353;
const int MN = 1e6 + 5;
int t, n, k;
int arr[MN];

int solve(){
    cin >> n >> k;
    FR(i, n) cin >> arr[i];
    ll ans = 1;
    FOR(i, n-k, n) if(arr[i] > 0) return 0;
    FOR(i, 1, k+1) ans = ans * i % MOD;

    FR(i, n-k){
        if(arr[i] == 0) ans = ans * (k+1) % MOD;
        if(arr[i] == -1){
            int mul = k+1 + i;
            ans = ans * mul % MOD;
        }
    }

    return ans;
}

int main(){
    boost();
    cin >> t;
    while(t--) cout << solve() << '\n';
}