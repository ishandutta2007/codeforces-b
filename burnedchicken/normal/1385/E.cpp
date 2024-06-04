#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define pi 3.14159265358979323846264338328
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=200005;
//i_am_noob
int t,n,m,x,u,v,pos[maxn];
vector<int> adj[maxn],radj[maxn],order,vec1,vec2;
bool vis[maxn],flag;

void rdfs(int u){
    vis[u]=true;
    for(auto v: radj[u]) if(!vis[v]) rdfs(v);
    order.pb(u);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(n) adj[i].clear(),radj[i].clear(),vis[i]=false;
        order.clear(),vec1.clear(),vec2.clear();
        rep(m){
            cin >> x >> u >> v;
            u--,v--;
            if(x==1) adj[u].pb(v),radj[v].pb(u);
            else vec1.pb(u),vec2.pb(v);
        }
        rep(n) if(!vis[i]) rdfs(i);
        rep(n) pos[order[i]]=i;
        flag=false;
        rep(n) for(auto j: adj[i]) if(pos[j]<pos[i]) flag=true;
        if(flag){
            print1("NO");
            continue;
        }
        print1("YES");
        rep(n) for(auto j: adj[i]) print2(i+1,j+1);
        rep(sz(vec1)){
            if(pos[vec2[i]]>pos[vec1[i]]) print2(vec1[i]+1,vec2[i]+1);
            else print2(vec2[i]+1,vec1[i]+1);
        }
    }
    return 0;
}