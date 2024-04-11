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

const int N=4005,K=805;
int n,k,a[N][N],sm[N][N],sm2[N][N],dp[K][N];

void solve(int i,int l,int r,int L,int R)
{
	if(l>r) return;
	int ps=-1;
	for(int j=L;j<=min(R,mid);++j)
		if(dp[i][mid]>dp[i-1][j-1]+sm[j][mid])
			dp[i][mid]=dp[i-1][j-1]+sm[j][mid],ps=j;
	solve(i,l,mid-1,L,ps);solve(i,mid+1,r,ps,R);
}

signed main()
{
	n=read();k=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a[i][j]=read();
	for(int i=1;i<=n;++i)
		for(int j=i-1;j>=1;--j)
			sm2[i][j]=sm2[i][j+1]+a[i][j];
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			sm[i][j]=sm[i][j-1]+sm2[j][i];
	memset(dp,0x3f,sizeof(dp));dp[0][0]=0;
	for(int i=1;i<=k;++i)
		solve(i,1,n,1,n);
	write(dp[k][n]);
	return 0;
}