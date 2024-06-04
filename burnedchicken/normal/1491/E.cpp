#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

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
const int MOD=Mod2;
const int maxn=200005;
//i_am_noob
//#define wiwihorz  
int n,f[30],edge[maxn][2],par[maxn],cnt[maxn];
vector<int> vec;
vector<pii> adj[maxn];
bool vis[maxn],vis2[maxn],flag;

void dfs(int u, int par, int id, int x){
    cnt[u]=1;
    for(auto& [v,e]: adj[u]) if(v!=par&&!vis2[e]){
        dfs(v,u,e,x);
        cnt[u]+=cnt[v];
    }
    if(cnt[u]==f[x-1]||cnt[u]==f[x-2]) vec.pb(id);
}

void solve(int rt, int x){
    if(x<=1) return;
    vec.clear();
    dfs(rt,-1,-1,x);
    if(vec.empty()){
        print("NO");
        exit(0);
    }
    vis2[vec[0]]=true;
    int u=edge[vec[0]][0],v=edge[vec[0]][1];
    if(cnt[u]<cnt[v]){
        if(cnt[u]==f[x-2]){
            solve(u,x-2);
            solve(rt,x-1);
        }
        else{
            solve(u,x-1);
            solve(rt,x-2);
        }
    }
    else{
        if(cnt[v]==f[x-2]){
            solve(v,x-2);
            solve(rt,x-1);
        }
        else{
            solve(v,x-1);
            solve(rt,x-2);
        }
    }
}

void hhhhauraorz(){
    cin >> n;
    rep(n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        edge[i][0]=u,edge[i][1]=v;
        adj[u].pb({v,i}),adj[v].pb({u,i});
    }
    f[0]=f[1]=1;
    rep2(i,2,30) f[i]=f[i-1]+f[i-2];
    flag=false;
    int x;
    rep(30) if(n==f[i]) x=i,flag=true;
    if(!flag){
        print("NO");
        return;
    }
    solve(0,x);
    print("YES");
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