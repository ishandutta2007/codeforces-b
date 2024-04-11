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

const int N=505;
int t,n,c[N],a[N],b[N],ls[N*2],ans[N],sum;

inline int query()
{
	
	printf("? ");
	for(int i=1;i<=n;++i)
		write(a[i]),putchar(' ');
	puts("");fflush(stdout);
	return read();
}

signed main()
{
	t=1;
	while(t--)
	{
		n=read();
		for(int i=1;i<=n-1;++i)
			a[i]=n;
		for(int i=1;i<=n;++i)
		{
			a[n]=i;
			if(query())
			{
				ans[n]=n+1-i;
				break;
			}
		}
		if(ans[n]==0)
			ans[n]=1;
		a[n]=1;
		for(int i=2;i<=ans[n];++i)
		{
			for(int j=1;j<=n-1;++j)
				a[j]=i;
			ans[query()]=ans[n]+1-i;
		}
		a[n]=n;
		for(int i=ans[n];i<=n-1;++i)
		{
			for(int j=1;j<=n-1;++j)
				a[j]=i;
			ans[query()]=ans[n]+n-i;
		}
		printf("! ");
		for(int i=1;i<=n;++i)
			write(ans[i]),putchar(' ');
		puts("");fflush(stdout);
	}
	return 0;
}