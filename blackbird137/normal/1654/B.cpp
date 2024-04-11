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

const int N=2e5+5;
int t,n,ls[N][30],now[30];
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=26;++i)
			now[i]=n+1;
		for(int i=n;i>=1;--i)
		{
			for(int j=1;j<=26;++j)
				ls[i][j]=now[j];
			now[s[i]-'a'+1]=i;
		}
		int ps=0;
		for(int i=1;i<=n;++i)
			if(ls[i][s[i]-'a'+1]!=n+1)
				ps=i;
			else break;
		for(int i=ps+1;i<=n;++i)
			putchar(s[i]);
		puts("");
	}
	return 0;
}