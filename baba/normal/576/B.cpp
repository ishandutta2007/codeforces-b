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
const int N = int(1e5)+10;
int P[N];
VI g[N];
VVI cycle[N];
int sz;
VI curr;
int vis[N];
set<II> e;
void dfs(int u)
{
	vis[u]=1;
	curr.PB(u);
	sz++;
	for(int i=0;i<SZ(g[u]);i++)
	{
		int w = g[u][i];
		if(!vis[w])
			dfs(w);
	}
}
int main()
{
	int n;
	si(n);
	for(int i=1;i<=n;i++)
	{
		si(P[i]);
		g[i].PB(P[i]);
		g[P[i]].PB(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		curr.clear();
		sz=0;
		dfs(i);
		cycle[sz].PB(curr);
	}
	bool ok=false;
	bool case1=false;
	if(SZ(cycle[1])>0)
	{
		ok=true;
		case1=true;
	}
	else
	{
		if(SZ(cycle[2])>0)
		{
			ok=true;
			for(int i=3;i<N;i+=2)
				if(SZ(cycle[i])>0)
					ok=false;
		}
	}
	if(!ok)
	{
		puts("NO");
		return 0;
	}
	if(case1)
	{
		int u =cycle[1][0][0];
		for(int i=1;i<=n;i++)
			if(i!=u)
				e.insert(MP(u,i));
	}
	else 
	{
		int u = cycle[2][0][0];
		int v = cycle[2][0][1];
		e.insert(MP(u,v));
		for(int j=2;j<N;j+=2)
		{
			for(int i=(j==2?1:0);i<SZ(cycle[j]);i++)
			{
				for(int k=0;k<SZ(cycle[j][i]);k+=2)
				{
					e.insert(MP(u,cycle[j][i][k]));
					e.insert(MP(v,cycle[j][i][k+1]));
				}
			}
		}
	}
	puts("YES");
	for(auto it=e.begin();it!=e.end();it++)
		printf("%d %d\n",it->F,it->S);
	return 0;
}