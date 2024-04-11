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

const int N=105;
int t,n,a[N],b[N],dp[N][N*N],ans;

signed main()
{
	t=read();
	while(t--)
	{
		memset(dp,0x3f,sizeof(dp));
		n=read();ans=0;
		for(int i=1;i<=n;++i)
			a[i]=read(),ans+=a[i]*a[i];
		for(int i=1;i<=n;++i)
			b[i]=read(),ans+=b[i]*b[i];
		ans*=(n-1);
		dp[0][0]=0;
		for(int i=1,now=0;i<=n;++i)
		{
			
			for(int j=0;j<=(i-1)*100;++j)
			{
				dp[i][j+a[i]]=min(dp[i][j+a[i]],dp[i-1][j]+a[i]*j+b[i]*(now-j));
				dp[i][j+b[i]]=min(dp[i][j+b[i]],dp[i-1][j]+b[i]*j+a[i]*(now-j));
			}
			now+=a[i]+b[i];
		}
		int tmp=INF;
		for(int i=0;i<=100*n;++i)
			tmp=min(tmp,dp[n][i]*2);
		write(ans+tmp);puts("");
	}
	return 0;
}