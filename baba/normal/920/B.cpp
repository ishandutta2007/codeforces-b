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
const int N = 1e4 + 10;
VI L[N], R[N];
int ans[N];
int main()
{
  int t;si(t);
  while(t--){
    int n;si(n);
    for(int i = 1; i <= n; i++){
      int l, r;
      si(l);si(r);
      L[l].PB(i);
      R[r].PB(i);
      ans[i] = 0;
    }
    set<int> S;
    for(int ct = 1; ct < N; ct++){
      for(auto y : L[ct]){
        S.insert(y);
      }
      int guy = -1;
      if(!S.empty()){
        guy = *S.begin();
        S.erase(S.begin());
      }
      for(auto y : R[ct]){
        S.erase(y);
      }
      if(guy == -1)continue;
      ans[guy] = ct;
    }
    for(int i = 1; i <= n; i++)
      printf("%d ", ans[i]);
    puts("");
    REP(i, N){
      L[i].clear();
      R[i].clear();
    }
  }
	return 0;
}