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

int ans[maxn];
//int ans[maxn];
bool np[maxn];

signed main(){

    IOS();

    int t; cin>>t;
    ans[1] = 1;
    for (int i = 2; i<=1000000; ++i) {
        if (!np[i]) {
            for (int j = i + i; j<=1000000; j+=i) {
                np[j] = 1;
            }
        }
    }
    for (int i = 2; i<=1000000; ++i) {
        ans[i] = ans[i-1];
        if (!np[i]) {
            ++ans[i];
//            bug("np", i);
        }
        int ss = (int)(0.5+sqrt(i));
        if (ss * ss == i && !np[ss]) {
        bug(i, ss);
            --ans[i];
        }
        if (i <= 10) bug(i, ans[i]);
    }

    for (int i = 0; i <t; ++i) {
        int x; cin>>x; cout<<ans[x]<<endl;
    }

}