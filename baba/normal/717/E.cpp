//Mobius_Treap
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
const int N = int(2e5)+10;
VI g[N];
int A[N],cnt;
void dfs(int u,int p){
  printf("%d ",u);
  A[u] ^= 1;
  for(auto w : g[u])
    if(w!=p){
      dfs(w,u);
      printf("%d ",u);
      A[u] ^= 1;
    }
  if(A[u])return;
  printf("%d %d ",p,u);
  A[p] ^= 1;
  A[u] ^= 1;
  assert(A[u]);
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++){
    si(A[i]);if(A[i]==-1)A[i] = 0;
    cnt += (A[i] == 0);
  }
  for(int i=1;i<n;i++){
    int u,v;
    si(u);si(v);
    g[u].PB(v);
    g[v].PB(u);
  }
  printf("%d ",1);
  if(!cnt)return 0;
  for(auto w : g[1]){
    dfs(w,1);
    if(w!=g[1].back()){
      printf("%d ",1);
      A[1] ^= 1;
    }
  }
  if(!A[1])printf("%d ",1);
  puts("");

  return 0;
}