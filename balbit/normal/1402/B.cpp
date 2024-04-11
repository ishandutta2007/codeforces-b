#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)

#define pb push_back
#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) for (int i = 1; i<=n; ++i)

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do( T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do( T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT


const int maxn = 3e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

int save(string s) {
    int re = 0;
    REP(i, SZ(s)) {
        if (s[i] == '1') break;
        ++re;
    }
    return re;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
    bug(1,2,rnd());

    int t; cin>>t;
    while (t--) {
        string s;cin>>s;int n = SZ(s);
        int n1= 0 ;for (char c :s) n1 += c == '1';
        int s0 = save(s); reverse(ALL(s)); s0 += save(s);
        if (s0 > n) s0 = n;
        cout<<n-s0-n1<<endl;

    }

}