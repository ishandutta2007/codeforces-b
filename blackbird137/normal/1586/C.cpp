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

const int N=1e6+5;
int n,m,sum[N];
char s[2][N];

signed main()
{
	n=read();m=read();
	scanf("%s",s[1]+1);
	for(int i=2;i<=n;++i)
	{
		scanf("%s",s[i&1]+1);
		for(int j=1;j<=m-1;++j)
			if(s[i&1][j]=='X'&&s[(i&1)^1][j+1]=='X')
				sum[j]=1;
	}
	for(int i=2;i<=m;++i)
		sum[i]+=sum[i-1];
	int q=read();
	while(q--)
	{
		int l=read(),r=read();
		if(sum[r-1]-sum[l-1]!=0)
			puts("NO");
		else puts("YES");
	}
	return 0;
}