#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

signed main()
{
	int t=read(),n,m;
	while(t--)
	{
		n=read();m=read();
		int a=0;
		for(int i=1;i<=n;++i)
			a+=read();
		if(a==m) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}