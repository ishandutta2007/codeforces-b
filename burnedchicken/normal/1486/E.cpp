#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=100005;
//i_am_noob
//#define wiwihorz  
int n,m,dis[maxn],minn[maxn];
vector<pii> adj[maxn];
priority_queue<pii,vector<pii>,greater<pii>> pq;
bool vis[maxn];

void hhhhauraorz(){
    cin >> n >> m;
    rep(m){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        adj[u].pb({v,w}),adj[v].pb({u,w});
    }
    rep(n) minn[i]=inf,dis[i]=inf;
    pq.push({0,0});
    while(!pq.empty()){
        auto [w,u]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        dis[u]=w;
        for(auto& [v,w1]: adj[u]) if(w1<minn[v]){
            for(auto& [x,w2]: adj[v]) if(dis[u]+(w1+w2)*(w1+w2)<dis[x]){
                dis[x]=dis[u]+(w1+w2)*(w1+w2);
                pq.push({dis[x],x});
            }
            minn[v]=w1;
        }
    }
    rep(n) print0(dis[i]==inf?-1:dis[i]);
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz(); 
    return 0;
}