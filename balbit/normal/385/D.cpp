#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 3e5+5;
#define double long double
const double PI = acosl(-1);

double dp[1<<20];

signed main(){
    IOS();
    int n, l, r; cin>>n>>l>>r;
    vector<double> x(n), y(n);
    vector<double> a(n);
    for (int i = 0; i<n; ++i) {
        cin>>x[i]>>y[i]>>a[i];
        a[i] = a[i] * PI / 180.0;
        bug(a[i]);
    }
    dp[0] = l;
    for (int msk = 1; msk < 1<<n; ++msk) {
        dp[msk] = l;
        for (int i = 0; i<n; ++i) {
            if (msk & (1<<i)) {
                double Ax = dp[msk^(1<<i)];
                double ang = a[i] + atanl((Ax - x[i])/y[i]);
                if (ang >= PI/2.0) {
                    cout<<(double)(r-l)<<endl;
                    return 0;
                }
                bug(msk,i,ang);
                double to = tanl(ang) * y[i] + x[i];
                bug(to);
                dp[msk] = max(dp[msk], to);
            }
        }
    }
    bug(dp[1], dp[10]);
    bug(dp[(1<<n)-1]);
    cout<<fixed<<setprecision(10)<<min(dp[(1<<n)-1],(double)r)-l<<endl;
}