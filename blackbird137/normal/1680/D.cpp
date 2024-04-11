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

#define int long long
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

const int N=3005;
int n,k,a[N],s1[N],s2[N];

inline int query()
{
	for(int i=1;i<=n;++i)
		s1[i]=s1[i-1]+a[i],s2[i]=s2[i-1]+(a[i]==0);
	int res=-1;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
		{
			int l1=s1[i]-s2[i]*k,r1=s1[i]+s2[i]*k;
			int l2=s1[n]-s1[j]-(s2[n]-s2[j])*k,r2=s1[n]-s1[j]+(s2[n]-s2[j])*k;
			int l3=-r1-r2,r3=-l1-l2;
			int l4=s1[j]-s1[i]-(s2[j]-s2[i])*k;
			int r4=s1[j]-s1[i]+(s2[j]-s2[i])*k;
			l4=max(l4,l3);r4=min(r4,r3);
			if(l4>r4) continue;
			res=max(res,r4);
		}
	return res;
}

signed main()
{
	n=read();k=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	int ans=query();
	for(int i=1;i<=n;++i)
		a[i]=-a[i];
	ans=max(ans,query());
	if(ans==-1)
	{
		puts("-1");
		return 0;
	}
	write(ans+1);
	return 0;
}