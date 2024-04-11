#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<int, int>
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

pii hi[5000001];
bool rp[200005];
int oid[200005];

void go(int a, int b, int c, int d) {
    bug(a,b,c,d);
    --a;--b;--c;--d;
    cout<<oid[a]+1<<' '<<oid[b]+1<<' '<<oid[c]+1<<' '<<oid[d]+1<<endl;
}
    vector<int> a;

void hm(int j, int i) {
    if (hi[a[j] + a[i]].f == -1) {
                hi[a[j]+a[i]] = {j+1,i+1};
            }else{
                bug("Hey");
                cout<<"YES"<<endl;
                go(hi[a[j]+a[i]].f,hi[a[j]+a[i]].s,i+1,j+1);
                exit(0);
            }
}

signed main(){
    IOS();
    fill(hi, hi+5000001, pii{-1,-1});
    int n; cin>>n; a.resize(n);
    REP(i,n) {
        cin>>a[i];
    }
    REP(i,n) oid[i] = i;
    sort(oid, oid+n, [&](int i, int b){return a[i] < a[b];});
//    REP(i,n) bug(oid[i]);
    sort(ALL(a));
    int rep = -1;
    REP(i,n) {
        if (i && a[i] == a[i-1]) {
            rp[i] = 1;
            if (rep == -1) {
                rep = i+1;
                hm(i-1,i);
            }else{
                if (rep == i) continue;
                cout<<"YES"<<endl;
                go(rep-1,i+1,rep,i);
                return 0;
            }
            continue;
        }
        for (int j = 0; j<i; ++j) {
            if (rp[j]) continue;
            hm(j,i);
        }
    }
    cout<<"NO"<<endl;


}