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
const int N = 2002;
const int MOD = int(1e9)+7;
LL dp[N][N];
int main()
{
	dp[0][0]=1;
	for(int i=1;i<N-1;i++)
		for(int j=0;j<N-1;j++)
			if(j)dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
			else dp[i][j]=dp[i-1][j+1];
	LL ans=0;
	fast_io;
	int n,m;cin>>n>>m;
	string s;cin>>s;
	int l=n-m,mn=0,val=0;
	for(int i=0;i<SZ(s);i++)
	{
		if(s[i]=='(')val++;
		else val--;
		mn=min(mn,val);
	}
	mn=-mn;
	for(int p=0;p<=l;p++)
	{
		int q = l-p;
		for(int pp=0;pp<=l;pp++)
		{
			if(mn>pp)continue;
			if(pp+val>=N)continue;
			ans = (ans + dp[p][pp]*dp[q][pp+val])%MOD;
		}
	}
	lldout(ans);
	return 0;
}