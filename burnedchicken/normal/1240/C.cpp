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
 
const int maxn=500005;
//i_am_noob
int q,n,k,u,v,w,dp[maxn][2],fa[maxn],a[maxn];
vector<pii> adj[maxn];

void dfs(int u){
	vector<int> tmp;
	int tmp1=0;
	rep(sz(adj[u])){
		int v=adj[u][i].first;
		int w=adj[u][i].second;
		if(fa[u]!=v){
			fa[v]=u;
			dfs(v);
			tmp.pb(w-dp[v][0]+dp[v][1]);
			tmp1+=dp[v][0];
		}
	}
	sort(all(tmp));
	reverse(all(tmp));
	rep(min(sz(tmp),k-1)) if(tmp[i]>0) tmp1+=tmp[i];
	dp[u][0]=dp[u][1]=tmp1;
	if(sz(tmp)>=k) if(tmp[k-1]>0) dp[u][0]+=tmp[k-1];
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> q;
	while(q--){
		cin >> n >> k;
		rep(n) adj[i].clear();
		rep(n-1){
			cin >> u >> v >> w;
			u--,v--;
			adj[u].pb(mp(v,w));
			adj[v].pb(mp(u,w));
		}
		fa[0]=-1;
		dfs(0);
		print1(dp[0][0]);
	}
	return 0;
}