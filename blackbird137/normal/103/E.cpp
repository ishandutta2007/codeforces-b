#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=305;
int n,nm[N],a[N][N],to[N],p[N];

struct Dinic1
{
	static const int _N=N*N*2,_M=N*N*2;
	
	int s,t,k,id1[N],id2[N],dep[_N];
	
	struct Edge
	{
		int v,w,ne;
	}e[_M*2];
	int head[_N],cur[_N],tot;
	
	inline void add(int u,int v,int w)
	{
		e[++tot]=(Edge){v,w,head[u]};head[u]=tot;
		e[++tot]=(Edge){u,0,head[v]};head[v]=tot;
	}
	
	inline bool bfs()
	{
		for(int i=1;i<=k;++i)
			dep[i]=0,cur[i]=head[i];
		queue<int> qu;
		dep[s]=1;qu.push(s);
		while(!qu.empty())
		{
			int u=qu.front();
			qu.pop();
			for(int i=head[u];i;i=e[i].ne)
			{
				int v=e[i].v;
				if(!e[i].w||dep[v])
					continue;
				dep[v]=dep[u]+1;
				qu.push(v);
			}
		}
		return dep[t];
	}
	
	inline int dinic()
	{
		int res=0;
		while(bfs())
		{
			while(1)
			{
				int tmp=dfs(s,INF);
				res+=tmp;
				if(!tmp) break;
			}
		}
		return res;
	}
	
	int dfs(int u,int flow)
	{
		if(u==t) return flow;
		for(int &i=cur[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(!e[i].w||dep[v]!=dep[u]+1)
				continue;
			int tmp=dfs(v,min(flow,e[i].w));
			if(tmp)
			{
				e[i].w-=tmp;
				e[fan(i)].w+=tmp;
				return tmp;
			}
		}
		return 0;
	}
	vector<int> ed;
	inline void build()
	{
		for(int i=1;i<=n;++i)
			id1[i]=i,id2[i]=i+n;
		k=n*2;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=nm[i];++j)
			{
				add(id1[i],id2[a[i][j]],1);
				ed.push_back(tot);
			}
		s=++k;t=++k;
		for(int i=1;i<=n;++i)
		{
			add(s,id1[i],1);
			add(id2[i],t,1);
		}
		dinic();
		for(auto i:ed)
		{
			int u=e[i].v;
			int v=e[i-1].v;
			if(e[i].w)
				to[v-n]=u;
		}
	}
}din1;

struct Dinic2
{
	static const int _N=N*N*2,_M=N*N*2;
	
	int s,t,k,dep[_N],id[N];
	
	struct Edge
	{
		int v,w,ne;
	}e[_M*2];
	int head[_N],cur[_N],tot;
	
	inline void add(int u,int v,int w)
	{
		e[++tot]=(Edge){v,w,head[u]};head[u]=tot;
		e[++tot]=(Edge){u,0,head[v]};head[v]=tot;
	}
	
	inline bool bfs()
	{
		for(int i=1;i<=k;++i)
			dep[i]=0,cur[i]=head[i];
		queue<int> qu;
		dep[s]=1;qu.push(s);
		while(!qu.empty())
		{
			int u=qu.front();
			qu.pop();
			for(int i=head[u];i;i=e[i].ne)
			{
				int v=e[i].v;
				if(!e[i].w||dep[v])
					continue;
				dep[v]=dep[u]+1;
				qu.push(v);
			}
		}
		return dep[t];
	}
	
	inline int dinic()
	{
		int res=0;
		while(bfs())
		{
			while(1)
			{
				int tmp=dfs(s,INF);
				res+=tmp;
				if(!tmp) break;
			}
		}
		return res;
	}
	
	int dfs(int u,int flow)
	{
		if(u==t) return flow;
		for(int &i=cur[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(!e[i].w||dep[v]!=dep[u]+1)
				continue;
			int tmp=dfs(v,min(flow,e[i].w));
			if(tmp)
			{
				e[i].w-=tmp;
				e[fan(i)].w+=tmp;
				return tmp;
			}
		}
		return 0;
	}
	inline int build()
	{
		int all=0;
		s=++k;t=++k;
		for(int i=1;i<=n;++i)
			id[i]=++k;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=nm[i];++j)
				add(id[i],id[to[a[i][j]]],INF);
		for(int i=1;i<=n;++i)
			if(p[i]>=0) add(s,id[i],p[i]),all+=p[i];
			else add(id[i],t,-p[i]);
		return all-dinic();
	}
}din2;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		nm[i]=read();
		for(int j=1;j<=nm[i];++j)
			a[i][j]=read();
	}
	for(int i=1;i<=n;++i)
		p[i]=-read();
	din1.build();
	write(-din2.build());
	return 0;
}