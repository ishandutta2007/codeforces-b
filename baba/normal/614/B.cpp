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


int main()
{
	fast_io;
	int n;cin>>n;
	string ans="1",s;
	int zeros=0;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s[0]=='0')
		{
			dout(0);
			return 0;
		}
		if(s[0]=='1')
		{
			bool ok=true;
			for(int i=1;i<SZ(s);i++)
				if(s[i]!='0')
					ok=false;
			if(ok)zeros+=SZ(s)-1;
			else ans=s;
		}
		else ans = s;
	}
	for(int i=0;i<zeros;i++)
		ans+='0';
	cout<<ans<<"\n";
	return 0;
}