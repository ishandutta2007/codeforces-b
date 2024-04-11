#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

int t, n, k;

struct Num {
    int arr[20];

    Num operator-(Num nm){
        Num res{};
        for (int i = 0; i < 20; ++i) {
            res.arr[i] = (arr[i] - nm.arr[i] + k) % k;
        }
        return res;
    }

    Num operator+(Num nm){
        Num res{};
        for (int i = 0; i < 20; ++i) {
            res.arr[i] = (arr[i] + nm.arr[i]) % k;
        }
        return res;
    }

    int toBase10(){
        int res = 0;
        for (int i = 19; i >= 0; --i) {
            res = res*k + arr[i];
        }
        return res;
    }
};

Num fromBase10(int x){
    Num res{};
    for (int i = 0; i < 20; ++i) {
        res.arr[i] = x % k;
        x /= k;
    }
    return res;
}

void solve(){
    cin >> n >> k;

    Num cur{};
    bool sign = false;

    for (int i = 0; i < n; ++i) {
        Num y = sign ? cur - fromBase10(i) : cur + fromBase10(i);
        cout << y.toBase10() << endl;
        int r;
        cin >> r;
        //if(r == 1) return;
        sign ^= 1;
        cur = y - cur;
    }
}

int main(){
    cin >> t;
    while(t--){
        solve();
    }
}