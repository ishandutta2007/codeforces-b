//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(1e5)+10;
const int LOGN = 20;
VI g[N];
int level[N],DP[LOGN][N],arr[N],dep[N],T;
void dfs(int x,int p){
  DP[0][x] = p;
  arr[x] = ++T;
  for(auto y : g[x]){
    if(y == p)continue;
    level[y] = level[x] + 1;
    dfs(y,x);
  }
  dep[x] = ++T;
}
bool anc(int p, int x){
  return arr[x] >= arr[p] && dep[x] <= dep[p];
}
int lca(int a,int b){
  if(level[a] > level[b])swap(a,b);
  int d = level[b] - level[a];
  for(int i=LOGN-1; i >= 0; i--)
    if(d & (1 << i))
      b = DP[i][b];
  if(a == b)return a;
  for(int i=LOGN-1; i >= 0; i--)
    if(DP[i][a] != DP[i][b])
      a = DP[i][a], b = DP[i][b];
  return DP[0][a];
}
int dist(int a,int b){
  return level[a] + level[b] - 2 * level[lca(a,b)];
}
int compute(int s,int t,int f){
  int sLCA = lca(s,f);
  int tLCA = lca(t,f);
  if(sLCA == s){
    return level[f] - max(level[s],level[tLCA]);
  }
  if(sLCA == f){
    return tLCA != f ? 0 : level[lca(s,t)] - level[f];
  }
  if(anc(s,tLCA)){
    return level[s] + level[f] - 2 * level[sLCA];
  }
  if(anc(f,tLCA)){
    return 0;
  }
  if(anc(tLCA,sLCA) && tLCA != sLCA){
    return level[f] - level[sLCA];
  }
  int stLCA = lca(s,t);
  if(anc(tLCA,stLCA))
    return dist(stLCA,f);
  return level[f] - level[tLCA];
}
int main()
{
  int n,q;
  si(n);si(q);
  for(int i=2;i<=n;i++){
    int x;si(x);
    g[x].PB(i);
    g[i].PB(x);
  }
  dfs(1,1);
  for(int i=1;i<LOGN;i++)
    for(int j=1;j<=n;j++)
      DP[i][j] = DP[i-1][DP[i-1][j]];
  while(q--){
    int s[3];
    REP(i,3)si(s[i]);
    vector<int> perm = {0,1,2};
    int ans = 0;
    do{
      ans = max(ans,compute(s[perm[0]],s[perm[1]],s[perm[2]]));
    }while(next_permutation(ALL(perm)));
    dout(1+ans);
  }
	return 0;
}