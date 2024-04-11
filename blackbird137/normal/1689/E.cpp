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

const int N=2005;
int t,n,a[N],fa[N];

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline bool check()
{
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=30;i>=0;--i)
	{
		int ls=-1;
		for(int j=1;j<=n;++j)
			if((a[j]>>i)&1)
			{
				if(ls==-1) ls=j;
				else fa[find(ls)]=find(j);
			}
	}
	for(int i=2;i<=n;++i)
		if(find(i)!=find(1))
			return  0;
	return 1;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();int ans=0;
		for(int i=1;i<=n;++i)
			a[i]=read(),ans+=(a[i]==0),a[i]=max(a[i],1);
		if(check())
		{
			write(ans);puts("");
			for(int i=1;i<=n;++i)
				write(a[i]),putchar(' ');
			puts("");continue;
		}
		int flag=0;
		for(int i=1;i<=n;++i)
		{
			a[i]++;
			if(check())
			{
				write(ans+1);puts("");
				for(int i=1;i<=n;++i)
					write(a[i]),putchar(' ');
				flag=1;puts("");break;
			}
			a[i]--;
		}
		if(flag) continue;
		for(int i=1;i<=n;++i)
		{
			a[i]--;
			if(check())
			{
				write(ans+1);puts("");
				for(int i=1;i<=n;++i)
					write(a[i]),putchar(' ');
				flag=1;puts("");break;
			}
			a[i]++;
		}
		if(flag) continue;
		int mn=1e9,mx=-1e9,ma=-1e9;
		for(int i=1;i<=n;++i)
			ma=max(ma,lowbit(a[i]));
		for(int i=1;i<=n;++i)
			if(lowbit(a[i])==ma)
				mn=min(mn,i),mx=max(mx,i);
		a[mn]++;a[mx]--;
		write(ans+2);puts("");
		for(int i=1;i<=n;++i)
			write(a[i]),putchar(' ');
		puts("");
	}
	return 0;
}