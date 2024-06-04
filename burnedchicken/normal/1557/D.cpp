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
const int maxn=300005;

//i_am_noob
//#define wiwihorz  
int n,m,cnt[maxn],dp[maxn],pre[maxn],res;
vector<array<int,3>> vec;
vector<int> adj[maxn];
set<int> st;
bool good[maxn];

void orzck(){
    cin >> n >> m;
    rep(m){
        int x,l,r;
        cin >> x >> l >> r;
        x--;
        vec.pb({l,1,x}),vec.pb({r+1,-1,x});
    }
    sort(all(vec));
    rep(sz(vec)){
        bug(vec[i][0],vec[i][1],vec[i][2]);
        cnt[vec[i][2]]+=vec[i][1];
        if(!cnt[vec[i][2]]) st.erase(vec[i][2]);
        if(vec[i][1]==1&&cnt[vec[i][2]]==1){
            bug(i);
            auto it=st.lower_bound(vec[i][2]);
            bug(it==st.begin());
            if(it!=st.end()) adj[*it].pb(vec[i][2]);
            if(it!=st.begin()){
                bug(i);
                it--;
                adj[vec[i][2]].pb(*it);
            }
            st.insert(vec[i][2]);
        }
    }
    rep(n){
        for(auto j: adj[i]){
            if(dp[j]>dp[i]) dp[i]=dp[j],pre[i]=j;
            bug(i,j);
        }
        dp[i]++;
        chkmax(res,dp[i]);
    }
    print(n-res);
    int cur=max_element(dp,dp+n)-dp;
    rep1(_,res) good[cur]=1,cur=pre[cur];
    rep(n) if(!good[i]) print0(i+1);
    cout << "\n";
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