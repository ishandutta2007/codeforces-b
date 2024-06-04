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

const int N = 1e3 + 10;
int A[N], T[N], L[N], R[N], ans[N], B[N];
int main()
{
   int n, m;
   si(n);si(m);
   for(int i = 0; i < m; i++){
     scanf("%d %d %d", T + i, L + i, R + i);
     if(T[i]){
       A[L[i]] += 1;
       A[R[i]] -= 1;
     }
   }
   int max = 1e9;
   for(int i = 1; i <= n; i++){
     A[i] += A[i - 1];
     if(!A[i]){
       ans[i] = --max;
       B[i] = 1;
     }
     else {
       ans[i] = 1;
     }
     B[i] += B[i - 1];
   }
   bool ok = true;
   for(int i = 0; i < m; i++){
     if(!T[i]){
       ok &= (B[R[i] - 1] - B[L[i] - 1] > 0);
     }
   }
   if(ok){
     puts("YES");
     for(int i = 1; i <= n; i++){
       printf("%d ", ans[i]);
     }
     puts("");
   }
   else {
     puts("NO");
   }

	return 0;
}