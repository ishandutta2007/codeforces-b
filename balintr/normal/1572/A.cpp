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
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 2e5 + 5;
int t, n;
vi adjList[MN];
int deg[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; ++i) {
            adjList[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            cin >> deg[i];
            for (int j = 0; j < deg[i]; ++j) {
                int b; cin >> b;
                b--;
                adjList[b].pb(i);
            }
        }

        int ans = 1;
        minPq<pii> pq;
        for (int i = 0; i < n; ++i) {
            if(deg[i] == 0) pq.push({1, i});
        }

        while(!pq.empty()){
            auto [times, n1] = pq.top(); pq.pop();
            ans = max(ans, times);

            for(int n2 : adjList[n1]){
                if(--deg[n2] == 0){
                    if(n2 < n1) pq.push({times + 1, n2});
                    else pq.push({times, n2});
                }
            }
        }

        int degS = 0;
        for (int i = 0; i < n; ++i) {
            degS += deg[i];
        }

        cout << (degS ? -1 : ans) << '\n';
    }
}