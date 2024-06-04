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
const int N = int(1e3)+10;
VI ans;
multiset<int> S;
int main()
{
	int n;si(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int x;si(x);
			S.insert(-x);
		}
	if(n==1)
	{
		dout(-*S.begin());
		return 0;
	}
	ans.PB(-*S.begin());
	S.erase(S.begin());
	while(!S.empty())
	{
		int x = -*S.begin();
		S.erase(S.begin());
		for(int i=0;i<SZ(ans);i++)
		{
			int y = __gcd(ans[i],x);
			S.erase(S.find(-y));
			S.erase(S.find(-y));
		}
		ans.PB(x);
	}
	for(int i=0;i<SZ(ans);i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}