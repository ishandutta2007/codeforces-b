#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e5+5;

vector<int> g[maxn];
vector<int> gt[maxn];

vector<int> ord; bool seen[maxn];

void dfs1(int v) {
    seen[v] = 1;
    for (int u : g[v]) {
        if (!seen[u]) {
            dfs1(u);
        }
    }
    ord.pb(v);
}

void dfs2(int v) {
//    assert(!seen[v]);
    seen[v] = 1;
    bug(v, seen[v]);
    for (int u : gt[v]) {
        if (!seen[u]) {
            dfs2(u);
        }
    }
}

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        REP(i,n) cin>>a[i];
        vector<int> b(n);
        vector<pii> y1, y2;
        REP(i,n) {
            cin>>b[i];
            y1.pb({a[i], i});
            y2.pb({b[i], i});
        }
        sort(ALL(y1));
        sort(ALL(y2));
        REP(i,n+1) {
            g[i].clear(); gt[i].clear();
        }
        REP1(i, n-1) {
            g[y1[i].s].pb(y1[i-1].s);
            g[y2[i].s].pb(y2[i-1].s);
            gt[y1[i-1].s].pb(y1[i].s);
            gt[y2[i-1].s].pb(y2[i].s);
        }
        fill(seen, seen+n+2, 0);
        ord.clear();
        REP(i,n) {
            if (!seen[i]) {
                dfs1(i);
            }
        }
        bug(ord.back());
        fill(seen, seen+n+2, 0);
        dfs2(ord.back());
        REP(i,n) {
            cout<<seen[i];
        }
        cout<<endl;
    }


}