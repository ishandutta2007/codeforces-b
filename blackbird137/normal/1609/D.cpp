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
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

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

const int N=1e3+5;
int n,m,vis[N],fa[N],siz[N],k,a[N];

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline bool merge(int x,int y)
{
	int f1=find(x),f2=find(y);
	if(f1!=f2) siz[f1]+=siz[f2],fa[f2]=f1;
	return f1==f2;
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		fa[i]=i,siz[i]=1;
	int now=1;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		now+=merge(u,v);k=0;
		for(int j=1;j<=n;++j)
			if(find(j)==j)
				a[++k]=siz[j];
		sort(a+1,a+1+k);int ans=0;
		for(int j=1;j<=k&&j<=now;++j)
			ans+=a[k-j+1];
		write(ans-1);puts("");
	}
	return 0;
}