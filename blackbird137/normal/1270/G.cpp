#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
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
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
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

const int N=1e6+5;
int t,n,st[N],vis[N],top,fl;

vector<int> ans;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u)
{
	vis[u]=1;st[++top]=u;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v])
		{
			int x;
			do
			{
				x=st[top--];
				ans.push_back(x);
			}while(x!=v);
			fl=1;
		}
		else
			dfs(v);
		if(fl) return;
	}
	vis[u]=0;
	--top;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			add(i,i-read());
		for(int i=1;i<=n&&!fl;++i)
			dfs(i);
		write(ans.size());puts("");
		for(int i=0;i<ans.size();++i)
			write(ans[i]),putchar(' ');
		puts("");
		for(int i=1;i<=n;++i)
			head[i]=0,vis[i]=0;
		tot=0;top=0;fl=0;
		ans.clear();
	}
	return 0;
}