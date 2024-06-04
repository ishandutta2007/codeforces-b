//TooWeakTooSlow
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
const int N = int(3e5)+10;
const int INF = int(1e9);
int A[N], dp[N];
int main()
{
  int n;si(n);
  int k;si(k);
  FOR(i, 1, n + 1)si(A[i]);
  sort(A + 1, A + n + 1);
  REP(i, k)dp[i] = INF;
  dp[0] = 0;
  set<II> DP, cost;
  DP.insert({INF, 0});
  cost.insert({A[k] - A[1], 0});
  int add = 0;
  FOR(i, k, n + 1){
    dp[i] = min(cost.begin()->F + add, DP.begin()->F);
    DP.insert({dp[i-k+1], i-k+1});
    add += A[i + 1] - A[i];
    while(true){
      auto top = *DP.begin();
      if(top.F == INF)break;
      int idx = top.S, dpval = top.F;
      if(dpval > A[i+1] - A[idx + 1]){
        break;
      }
      DP.erase(DP.begin());
      cost.insert({A[i+1] - A[idx + 1] - add, idx});
    }
  }
  dout(dp[n]);
	return 0;
}