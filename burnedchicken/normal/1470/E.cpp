#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

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
#define bug(...) 777771449
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
inline modint H(int n, int m){return C(n+m-1,n);}
const int maxn=30005,maxm=5,maxk=7777714;

//i_am_noob
#define wiwihorz  
int n,c,q,a[maxn],cnt[maxm][maxn],cntb[maxm][maxn],cnts[maxm][maxn],sumb[maxm][maxn],sums[maxm][maxn];
int DE=1100'000'000'000'000'000;

bool cmp(int x, int y){return a[x]<a[y];}

void orzck(){
    cin >> n >> c >> q;
    rep(n) cin >> a[i];
    rep1(j,c+1) rep3(i,n,0){
        cntb[j][i]=cnts[j][i]=cnt[j][i]=0;
        if(i==n){
            cnt[j][i]=1;
            continue;
        }
        cnt[j][i]+=cnt[j][i+1];
        rep2(k,1,j+1) if(i+k+1<=n){
            cnt[j][i]+=cnt[j-k][i+k+1];
            if(a[i+k]<a[i]) cnts[j][i]+=cnt[j-k][i+k+1];
            else cntb[j][i]+=cnt[j-k][i+k+1];
        }
    }
    rep1(j,c+1) sumb[j][n]=sums[j][n]=0;
    rep1(j,c+1) rep3(i,n-1,0) sumb[j][i]=sumb[j][i+1]+cntb[j][i],sums[j][i]=sums[j][i+1]+cnts[j][i];
    while(q--){
        int x,y;
        cin >> x >> y;
        x--;
        if(cnt[c][0]<y){
            print(-1);
            continue;
        }
        int cur=0,s=c;
        bool flag=0;
        while(s){
            if(y==sums[s][cur]+1){//same
                print(a[x]);
                flag=1;
                break;
            }
            if(y<=sums[s][cur]){//smaller
                int l=cur,r=n-1;//first difference
                while(l<r){
                    int mid=l+r+1>>1;
                    if(y>sums[s][cur]-sums[s][mid]) l=mid;
                    else r=mid-1;
                }
                y-=sums[s][cur]-sums[s][l];
                if(x<l){
                    print(a[x]);
                    flag=1;
                    break;
                }
                vector<int> vec;
                rep2(i,1,s+1) if(l+i<n&&a[l+i]<a[l]) vec.pb(l+i);
                sort(all(vec),cmp);
                for(auto i: vec){
                    if(y>cnt[s-(i-l)][i+1]){
                        y-=cnt[s-(i-l)][i+1];
                        continue;
                    }
                    if(x<=i){
                        print(a[l+i-x]);
                        flag=1;
                        break;
                    }
                    s-=i-l;
                    cur=i+1;
                    break;
                }
                if(flag) break;
            }
            else{//bigger
                y-=sums[s][cur]+1;
                int l=cur,r=n-1;
                while(l<r){
                    int mid=l+r+1>>1;
                    if(y>sumb[s][mid]) r=mid-1;
                    else l=mid;
                }
                y-=sumb[s][l+1];
                if(x<l){
                    print(a[x]);
                    flag=1;
                    break;
                }
                vector<int> vec;
                rep2(i,1,s+1) if(l+i<n&&a[l+i]>a[l]) vec.pb(l+i);
                sort(all(vec),cmp);
                for(auto i: vec){
                    if(y>cnt[s-(i-l)][i+1]){
                        y-=cnt[s-(i-l)][i+1];
                        continue;
                    }
                    if(x<=i){
                        print(a[l+i-x]);
                        flag=1;
                        break;
                    }
                    s-=i-l;
                    cur=i+1;
                    break;
                }
                if(flag) break;
            }
        }
        if(!flag) print(a[x]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    // #ifdef i_am_noob
    // freopen("input1.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
    // freopen("output2.txt","w",stderr);
    // #endif
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