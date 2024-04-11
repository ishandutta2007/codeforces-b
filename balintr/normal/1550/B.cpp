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

int t, n, a, b;
string str;

int calc(int l, int r){
    int newL = l;
    int newR = r;
    if(str[l] != str[r]){
        while(str[newL] == str[l]) newL++;
        return 1 + calc(newL, newR);
    }

    while(str[newL] == str[l]) newL++;
    while(str[newR] == str[r]) newR--;
    if(newR < newL) return 1;
    return 1 + calc(newL, newR);
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> a >> b >> str;
        int res = a*n;
        if(b >= 0){
            res += b*n;
        }
        else {
            res += b*calc(0, n-1);
        }
        cout << res << '\n';
    }
}