#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
//#define int ll
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
#define inf 1010000000
//#define inf 4000000000000000000
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
const int maxn=4005,maxm=7777714,maxk=77;

//i_am_noob
//#define wiwihorz  
int n,m,k;
vector<pii> e1,e2;
int dp[maxk][maxn],cnt1[maxk],cnt2[maxk],fac[maxk],invfac[maxk];
ll res;

constexpr void add(int& x, int y){x+=y;if(x>=MOD) x-=MOD;}
int C(int n, int m){return 1ll*fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;}

void orzck(){
    fac[0]=1;
    rep2(i,1,maxk) fac[i]=1ll*fac[i-1]*i%MOD;
    invfac[0]=invfac[1]=1;
    rep2(i,2,maxk) invfac[i]=1ll*invfac[MOD%i]*(MOD-MOD/i)%MOD;
    rep2(i,2,maxk) invfac[i]=1ll*invfac[i]*invfac[i-1]%MOD;
    cin >> n >> m >> k;
    if(k&1){
        print(0);
        return;
    }
    rep(n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        e1.pb({u,v});
    }
    rep(m-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        e2.pb({u,v});
    }
    rep1(u,n){
        rep(k+1) rep1(j,n) dp[i][j]=0;
        dp[0][u]=1;
        rep(k){
            for(auto [x,y]: e1){
                add(dp[i+1][x],dp[i][y]);
                add(dp[i+1][y],dp[i][x]);
            }
        }
        //rep(k+1) rep1(j,n) bug(u,i,j,dp[i][j]);
        rep(k+1) add(cnt1[i],dp[i][u]);
    }
    rep1(u,m){
        rep(k+1) rep1(j,m) dp[i][j]=0;
        dp[0][u]=1;
        rep(k){
            for(auto [x,y]: e2){
                add(dp[i+1][x],dp[i][y]);
                add(dp[i+1][y],dp[i][x]);
            }
        }
        //rep(k+1) rep1(j,m) bug(u,i,j,dp[i][j]);
        rep(k+1) add(cnt2[i],dp[i][u]);
    }
    rep(k+1) res+=1ll*cnt1[i]*cnt2[k-i]%MOD*C(k,i)%MOD;
    print(res%MOD);
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