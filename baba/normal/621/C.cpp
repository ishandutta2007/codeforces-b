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
LL A[N],L[N],R[N],total[N],p;
int main()
{
	int n;si(n);
	sll(p);
	for(int i=1;i<=n;i++)
		scanf("%lld %lld\n",L+i,R+i);
	for(int i=1;i<=n;i++)
	{
	//	A[i]=upper_bound(ALL(P),R[i])-lower_bound(ALL(P),L[i]);
		A[i]=(R[i]/p) - ((L[i]-1)/p);
		total[i]=R[i]-L[i]+1;
	}
	A[0]=A[n];A[n+1]=A[1];
	total[0]=total[n];total[n+1]=total[1];
	double ans=0.0;
	for(int i=1;i<=n;i++)
	{
		ans = ans + (2000.0*A[i])/(total[i]);
		double pl = (1000.0*A[i-1])/total[i-1];
		double pr = (1000.0*A[i+1])/total[i+1];
		double p = pl + pr - (2*pl*pr)/1000.0;
		ans = ans + p*((total[i]-A[i])/(1.0*total[i]));
		pl = (2000.0*A[i-1])/total[i-1];
		p = (pl * A[i+1])/total[i+1];
		ans = ans + (p*(total[i]-A[i]))/total[i];
	//	trace(i,total[i],A[i],L[i],R[i],ans);
	}
	printf("%.9lf\n",ans);
	return 0;
}