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
const int N = int(7e4)+10;
unordered_map<string,VI> mp;
string ans[N];
int main()
{
  fast_io;
  int n;cin>>n;
  REP(t,n){
    string curr;cin>>curr;
    for(int i=0;i<SZ(curr);i++){
      string s = "";
      for(int j=i;j<SZ(curr);j++){
        s += curr[j];
        mp[s].PB(t);
      }
    }
  }
  for(auto it : mp){
    auto &v = it.S;
    int cnt = -1;
    bool ok = true;
    for(auto x : v){
      if(cnt == -1)
        cnt = x;
      else if(cnt != x)
        ok = false;
    }
    if(!ok)continue;
    if(ans[cnt].empty())ans[cnt] = it.F;
    else if(SZ(ans[cnt]) > SZ(it.F))ans[cnt] = it.F;
  }
  for(int i=0;i<n;i++)
    cout<<ans[i]<<"\n";
	return 0;
}