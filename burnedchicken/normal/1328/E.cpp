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
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a) 
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
using namespace __gnu_pbds;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
 
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
int n,u,v,dep[maxn],fa[maxn][20],q,k,a[maxn];
vector<int> adj[maxn];
bool ok;

void dfs(int u){
	dep[u]=u?dep[fa[u][0]]+1:0;
	rep2(i,1,20) fa[u][i]=fa[u][i-1]==-1?-1:fa[fa[u][i-1]][i-1];
	rep(sz(adj[u])){
		if(adj[u][i]==fa[u][0]) continue;
		fa[adj[u][i]][0]=u;
		dfs(adj[u][i]);
	}
}

bool direct(int u, int v){
	if(dep[v]>dep[u]) swap(u,v);
	rep(20) if(dep[u]-dep[v]&pow2(i)) u=fa[u][i];
	if(u==v) return true;
	return false;
}
 
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> q;
	rep(n-1){
		cin >> u >> v;
		u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fa[0][0]=-1;
	dfs(0);
	while(q--){
		cin >> k;
		rep(k) cin >> a[i];
		rep(k) a[i]--;
		rep(k) a[i]=a[i]?fa[a[i]][0]:0;
		ok=true;
		u=0;
		rep(k){
			if(!direct(u,a[i])){
				ok=false;
				break;
			}
			if(dep[a[i]]>dep[u]) u=a[i];
		}
		print1(ok?"YES":"NO");
	}
	return 0;
}