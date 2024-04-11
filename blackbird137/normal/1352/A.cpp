#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e4+5;
int t,n,ans[N],tot;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		int now=1;
		tot=0;
		while(n)
		{
			if(n%10!=0)
				ans[++tot]=now*(n%10);
			n/=10;
			now*=10;
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}