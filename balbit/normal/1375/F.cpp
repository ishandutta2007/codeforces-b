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
//#define endl '\n'
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

const int maxn = 1e6+5;

#define int ll

void ass(bool x) {
    if (!x) while (1);
}

signed main(){
    IOS();
    array<ll, 3> a;
    cin>>a[0]>>a[1]>>a[2];
    cout<<"First"<<endl;
    cout<<(100000000000)<<endl;
    int x; cin>>x;
    if (x == 0) return 0;
    a[x-1] += 100000000000;
    int smol = min({a[0], a[1], a[2]});
    int big = max({a[0], a[1], a[2]});
    int mid = 0;
    for (int i =0; i<3; ++i) if (a[i] != smol && a[i] != big) mid = a[i];
    cout<<big-mid+big-smol<<endl;
    int y; cin>>y;
    if (y == 0) return 0;
    a[y-1] += big-mid+big-smol;
    sort(ALL(a));
    ass(a[2] - a[1] == a[1] - a[0]);
    cout<<a[2] - a[1]<<endl;


}