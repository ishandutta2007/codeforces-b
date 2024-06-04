#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=_val%mod;if(val<0) val+=mod;}
    Modint operator +(const Modint& o) const {
        Modint res;
        res.val=val+o.val;
        if(res.val>=mod) res.val-=mod;
        return res;
    }
    Modint operator +(const int& o) const {return Modint(val+o);}
    Modint operator -() const {
        Modint res;
        res.val=-val;
        if(res.val<0) res.val+=mod;
        return res;
    }
    Modint operator -(const Modint& o) const {
        Modint res;
        res.val=val-o.val;
        if(res.val<0) res.val+=mod;
        return res;
    }
    Modint operator -(const int& o) const {return Modint(val-o);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val);}
    Modint operator *(const int& o) const {return Modint(val*(o%mod));}
    Modint operator +=(const Modint& o){*this=(*this)+o;return *this;}
    Modint operator -=(const Modint& o){*this=(*this)-o;return *this;}
    Modint operator *=(const Modint& o){*this=(*this)*o;return *this;}
    Modint Pow(int b) const {
        Modint tmp(val),ret(1);
        while(b){
            if(b&1) ret*=tmp;
            b>>=1;tmp*=tmp;
        }
        return ret;
    }
    Modint Pow(const Modint& a, int b) const {return a.Pow(b);}
    inline Modint inv() const {return (*this).Pow(mod-2);}
    Modint operator /(const Modint& o) const {return *this*o.inv();}
    Modint operator /(const int& o) const {return *this*Modint(o).inv();}
    bool operator ==(const Modint& o) const {return val==o.val;}
};
template<int mod>
ostream& operator << (ostream& o, Modint<mod> x){return o << x.val;}
template<int mod>
Modint<mod> operator +(const int& x, const Modint<mod>& y){return Modint<mod>(x+y.val);}
template<int mod>
Modint<mod> operator -(const int& x, const Modint<mod>& y){return Modint<mod>(x-y.val);}
template<int mod>
Modint<mod> operator *(const int& x, const Modint<mod>& y){return Modint<mod>(x%mod*y.val);}
#define modint Modint<MOD>
vector<modint> inv,fac,invfac;
void init_comb(int N){
    inv.resize(N),fac.resize(N),invfac.resize(N);
    inv[1]=1,fac[0]=1,invfac[0]=1;
    rep2(i,2,N) inv[i]=inv[MOD%i]*(MOD-MOD/i);
    rep2(i,1,N) fac[i]=fac[i-1]*i;
    rep2(i,1,N) invfac[i]=invfac[i-1]*inv[i];
}
inline modint C(int n, int m){return m>n||m<0?modint(0):fac[n]*invfac[m]*invfac[n-m];}

const int maxn=105;

//i_am_noob
//#define wiwihorz  
int n,m,l1[maxn],r1[maxn],l2[maxn],r2[maxn];
vector<pii> vec1,vec2,res;

void orzck(){
    cin >> n;
    rep(n) cin >> l1[i] >> r1[i];
    rep(n) r1[i]++;
    cin >> m;
    rep(m) cin >> l2[i] >> r2[i];
    rep(m) r2[i]++;
    rep(n){
        int x=l1[i];
        while(x+(x&-x)<=r1[i]) vec1.pb({x,x+(x&-x)}),x+=x&-x;
        int y=r1[i];
        while(y-(y&-y)>=x) vec1.pb({y-(y&-y),y}),y-=y&-y;
    }
    rep(m){
        int x=l2[i];
        while(x+(x&-x)<=r2[i]) vec2.pb({x,x+(x&-x)}),x+=x&-x;
        int y=r2[i];
        while(y-(y&-y)>=x) vec2.pb({y-(y&-y),y}),y-=y&-y;
    }
    for(auto [x,y]: vec1) bug(x,y);
    for(auto& [l,r]: vec1){
        int k=__lg(r-l);
        rep(m){
            int x=(l2[i]>>k)<<k;
            res.pb({l^x,(l^x)+pow2(k)});
            bug(l^x,(l^x)+pow2(k));
            if(x+pow2(k)<r2[i]){
                x+=pow2(k);
                res.pb({l^x,(l^x)+pow2(k)});
                bug(l^x,(l^x)+pow2(k));
            }
            x=(r2[i]-1>>k)<<k;
            res.pb({l^x,(l^x)+pow2(k)});
            bug(l^x,(l^x)+pow2(k));
            if(x-1>=l2[i]){
                x-=pow2(k);
                res.pb({l^x,(l^x)+pow2(k)});
                bug(l^x,(l^x)+pow2(k));
            }
        }
    }
    for(auto& [l,r]: vec2){
        int k=__lg(r-l);
        rep(n){
            int x=(l1[i]>>k)<<k;
            res.pb({l^x,(l^x)+pow2(k)});
            bug(l^x,(l^x)+pow2(k));
            if(x+pow2(k)<r1[i]){
                x+=pow2(k);
                res.pb({l^x,(l^x)+pow2(k)});
                bug(l^x,(l^x)+pow2(k));
            }
            x=(r1[i]-1>>k)<<k;
            res.pb({l^x,(l^x)+pow2(k)});
            bug(l^x,(l^x)+pow2(k));
            if(x-1>=l1[i]){
                x-=pow2(k);
                res.pb({l^x,(l^x)+pow2(k)});
                bug(l^x,(l^x)+pow2(k));
            }
        }
    }
    for(auto [x,y]: res) bug(x,y);
    sort(all(res));
    
    int l=-1,r=-1;
    modint tot=0,inv2=modint(2).inv();
    bug(sz(res));
    for(auto& [x,y]: res){
        if(x>r){
            bug(l,r);
            modint k1=l,k2=r;
            if(r>=0){
                tot+=(modint(k2*(k2+1))-modint((k1-1)*k1))*inv2;
            }
            bug(tot);
            l=x,r=y-1;
        }
        else chkmax(r,y-1);
    }
    modint k1=l,k2=r;
    if(r>=0) tot+=(modint(k2*(k2+1))-modint((k1-1)*k1))*inv2;
    print(tot);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}