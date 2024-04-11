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
// Num used bits
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);}
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);}

const int MN = 2e5 + 5;
int t, n;
int arr[MN];
ll prefix[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + arr[i];
        }
        ll total = arr[n-1];
        for (int i = 1; i < n; ++i) {
            total -= (ll)arr[i]*i - prefix[i-1];
        }
        cout << total << '\n';
    }
}